import argparse
import re
from typing import List
import os

parser = argparse.ArgumentParser(
                    prog='code_parser',
                    description='This utility combines all headers and sources into a single file. So that one can easily submit code to online judge system.')

parser.add_argument("--header", nargs='+')
parser.add_argument("--source", nargs='+')
parser.add_argument("-o", "--output")

args=parser.parse_args()
print(args.header)
print(args.source)



def expand(entry: str, visitMap: dict, buf: List[str]):
    if visitMap[entry]==True:
        return

    with open(entry) as f:
        code=f.readlines()

    code=[line.strip() for line in code]
    regex=r'#\s*include\s*\"(\w+.h)\"'
    
    # first pass scan
    for line in code:
        m=re.match(regex, line)
        if m:
            nextEntry=m.group(1)
            if visitMap[nextEntry]==False:
                expand(nextEntry, visitMap, buf)

    for line in code:
        m=re.match(regex, line)
        if m:
            continue
        buf.append(line+os.linesep)

    buf.append(os.linesep)
    visitMap[entry]=True


buf=[]
header_dict = dict.fromkeys(args.header, False)
source_dict = dict.fromkeys(args.source, False)

for i in args.header:
    expand(i, header_dict, buf)

for i in args.source:
    expand(i, {**header_dict, **source_dict}, buf)

with open(args.output, "w", encoding="utf-8") as f:
    f.writelines(buf)