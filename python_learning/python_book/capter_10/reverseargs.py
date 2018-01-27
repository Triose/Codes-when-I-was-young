# reverseargs.py
import sys

def printReversedArgs():
    args = sys.argv[1:]
    args.reverse()
    print(args)

if __name__ == "__main__": printReversedArgs()




