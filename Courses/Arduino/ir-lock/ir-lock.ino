#include <LiquidCrystal_I2C.h>
#include <string.h>

#define BUZZER 10 //蜂鸣器
#define LED_RED 13 //红灯
#define IR_IN 2 //红外接收

int pulse_width =0;//存储脉宽
int ir_code=0x00;//命令值

const int hex_values[] = {0xf30c, 0xef10, 0xee11, 0xed12, 0xeb14, 0xea15, 0xe916, 0xe718, 0xe619, 0xe51a};
const char char_values[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void timerInit(void) {
  TCCR1A = 0X00;
  TCCR1B = 0X05;
  TCCR1C = 0X00;
  TCNT1 = 0X00;
  TIMSK1 = 0X00;
}

//接收地址码和命令码脉
void pulse_deal() {
  int i;
  //执行8个0
  for(i=0; i<8; i++)
  {
    if(logic_value() != 0) //不是0
        return;
  }
  //执行6个1
  for(i=0; i<6; i++)
  {
    if(logic_value()!= 1) //不是1
        return;
  }
  //执行1个0
  if(logic_value()!= 0) //不是0
      return;
  //执行1个1
  if(logic_value()!= 1) //不是1
      return;
  //解析遥控器编码中的command指令
  ir_code=0x00;//清零
  for(i=0; i<16;i++ )
  {
    if(logic_value() == 1)
    {
      ir_code |=(1<<i);
    }
  }
}

//译码函数
void remote_decode(void) {
  TCNT1=0X00;
  while(digitalRead(IR_IN))//是高就等待
  {
    if(TCNT1>=1563)  //当高电平持续时间超过100ms，表明此时没有按键按下
    {
      ir_code = 0xff00;
      return;
    }
  }
  //如果高电平持续时间不超过100ms
  TCNT1=0X00;
  while(!(digitalRead(IR_IN))); //低等待
  pulse_width = TCNT1;
  TCNT1=0;
  if(pulse_width >= 140 && pulse_width <= 143)//9ms
  {
    while (digitalRead(IR_IN));//是高就等待
    pulse_width = TCNT1;
    TCNT1 = 0;
    if(pulse_width >= 68 && pulse_width <= 72)//4.5ms
    {
      pulse_deal();
      return;
    }
    else if(pulse_width >= 34 && pulse_width <= 36)//2.25ms
    {
      while(!(digitalRead(IR_IN)));//低等待
      pulse_width = TCNT1;
      TCNT1 = 0;
      if(pulse_width >= 7 && pulse_width <= 10)//560us
      {
        return;
      }
    }
  }
}

char remote_deal(void) {
  int index;
  char input_char;
  for (index = 0; index < 10; index++) {
    if (hex_values[index] == ir_code) {
      input_char = char_values[index];
    }
  }
  return input_char;
}

//判断逻辑值“0”和“1”子函数
char logic_value() {
  while(!(digitalRead(IR_IN))); //低等待
  pulse_width =TCNT1;
  TCNT1=0;
  if(pulse_width >= 7 && pulse_width <= 10)//低电平560us
  {
    while(digitalRead(IR_IN));//是高就等待
    pulse_width =TCNT1;
    TCNT1=0;
    if(pulse_width >=7&&pulse_width <=10)//接着高电平560us
      return 0;
    else if(pulse_width >=25&&pulse_width <=27) //接着高电平1.7ms
      return 1;
  }
  return -1;
}

LiquidCrystal_I2C lcd(0x20, 16, 2); // Address: 0x20, 2 rows 16 columns

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("enter passwd: ");

  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(IR_IN, INPUT);
  timerInit();
}

bool waitingForInput = false; // 状态变量，表示当前是否正在等待用户输入
static char input[17] = ""; // 声明静态数组，用于存储输入字符串，初始化为空字符串
void loop() {
  remote_decode();  // 译码

  // 如果正在等待用户输入且成功接收到字符
  if (waitingForInput && ir_code != 0x00) {

    char input_char = remote_deal();
    if (strlen(input) < 16) {
      char char_str[2]; // 将接收到的字符转换为字符串
      char_str[0] = input_char;
      char_str[1] = '\0';
      strcat(input, char_str); // 将接收到的字符添加到字符串末尾
    }
    waitingForInput = false; // 清除等待状态
    ir_code = 0x00; // 清除接收到的字符
    lcd.setCursor(0, 1);
    lcd.print(input);
  }

  // 如果没有在等待输入且成功接收到字符，则设置为等待输入状态
  if (!waitingForInput && ir_code != 0x00) {
    waitingForInput = true;
  }
  while(waitingForInput) {
    remote_decode();
    if (remote_deal())
      break;
  }
  bool active = false;
  if (strcmp(input, "7355608") == 0) {
    active = true;
  }

  if (active) {
    for (float sec = 30; sec > 0;) {
      if (sec > 24) {
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED_RED, HIGH);
        delay(200);
        sec -= 0.2;
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED_RED, LOW);
        delay(1800);
        sec -= 1.8;
      }
      if (sec <= 24 && sec > 16) {
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED_RED, HIGH);
        delay(200);
        sec -= 0.2;
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED_RED, LOW);
        delay(800);
        sec -= 0.8;
      }
      if (sec <=16 && sec > 8) {
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED_RED, HIGH);
        delay(200);
        sec -= 0.2;
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED_RED, LOW);
        delay(300);
        sec -= 0.3;
      }
      if (sec <= 8 && sec >= 0) {
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED_RED, HIGH);
        delay(200);
        sec -= 0.2;
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED_RED, LOW);
        delay(50);
        sec -= 0.05;
      }
    
      lcd.setCursor(0, 0);
      lcd.print("remaining sec:");
      lcd.print(sec);
      if (sec == 0) {
        lcd.setCursor(0, 0);
        lcd.print("Terrorists Win!");
      }
    }
  }
}