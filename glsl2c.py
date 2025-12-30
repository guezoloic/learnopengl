#!/usr/bin/env python3
import sys
from pathlib import Path

src = sys.argv[1]
dst = sys.argv[2]

if len(sys.argv) != 3 or not src.endswith((".glsl", ".vert", ".frag")):
    sys.exit(1)

# variable name
varname = src.replace("/", "_").replace(".", "_")

# read to binary mode
content = Path(src).read_bytes()

line = 12

with open(dst, "w") as f:
    # content array
    f.write(f"unsigned char {varname}[] = {{\n")
    
    for i, byte in enumerate(content):
        # tab
        if i % line == 0:
            f.write("\t")
        # hexa
        f.write(f"0x{byte:02x}, ")
        
        # LF/CRLF
        if (i + 1) % line == 0:
            f.write("\n")
    f.write("};\n")
    # content size
    f.write(f"unsigned int {varname}_len = {len(content)};")