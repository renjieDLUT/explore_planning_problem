import argparse


if __name__=="__main__":
    parser=argparse.ArgumentParser()
    parser.add_argument("first",type=float)
    parser.add_argument("second",type=float)

    args=parser.parse_args()

    print(args.first+args.second)