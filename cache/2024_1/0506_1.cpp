// 2的幂次方表示

#include <iostream>
using namespace std;

int getlen(int i)
{
	//计算二进制数n的位长度
	int len = 0;
	while (i)
	{
		i >>= 1;
		++len;
	}
	return len;
}

void convert(int num,int k)//转换二进制数的第k位，从最高位开始转换
{
	if (k == 0) return;    //第0位，不存在，数已经转换完毕

	int num_k = (num >> (k-1)) & 1;
	
	if (!num_k)            //第k位为0，则开始转换下一位
		convert(num, k - 1);
	else           
	{
		if (k != getlen(num)) cout << "+";//转换数的最高位时不用打印 +
		
		if (k == 1) cout << "2(0)";
		else if (k == 2) cout << "2";
		else 
		{
			cout << "2(";
			convert(k-1, getlen(k-1));//对幂指数进行转换
			cout << ")";
		}
		convert(num, k - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	convert(n, getlen(n));
	return 0;
}
