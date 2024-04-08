def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        try:
            n = int(input("Input the height: "))
        except ValueError:
            print("Not an integer")
        else:
            if n > 0:
                return n
        
main()