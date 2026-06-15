# Lorem

Generate lorem ipsum

```
usage: lorem [OPTIONS]

positional arguments:
 mode		generation mode: [w]ord, [l]ine/[s]entence, [p]aragraph (default: line)
 length		number of chunks to generate (default: 1)

options:
 -h --help		show this message

examples:
 lorem p 2  		generate 2 paragraphs
 lorem w 2	    	generate 2 words
 lorem l 2		    generate 2 lines/sentences
 lorem s 2  		generate 2 lines/sentences
 lorem 2	    	generate 2 lines/sentences
 lorem			    generate 1 line/sentence
 lorem p		    generate 1 paragraph
 lorem paragraph 2	generate 2 paragraphs
 lorem word 2		generate 2 words
 lorem line 2		generate 2 lines/sentences
 lorem sentence 2	generate 2 lines/sentences

```

## Building
`build.c` is the script used to build the project. To use it, bootstrap `build`
with gcc & run the executable to build the project
```
gcc build.c -o build
./build
```
Inspired by [nob](https://github.com/tsoding/nob.h)
