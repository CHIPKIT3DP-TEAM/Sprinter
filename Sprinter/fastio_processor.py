# python processor for chipkit_fastio.h
from sys import argv
from sys import exit

if len(argv) < 3 :
	print "usage = input file output file"
	exit(1)

# open the input file
in_filename = argv[1]

# open the output file
out_filename = argv[2]

infile = open(in_filename,'r');
outfile = open(out_filename,'w');

# read a line
for line in infile:
	g = line.split()
	if g[0] != '#': # if the first character is a #, treat the line as a comment.
		pin  = g[0] 	# the first number
		bit  = g[1] 	# the second number
		prt  = g[2].upper()     # the third letter

		# create the macro's for the line
		outfile.write("#define DIO"+pin+"_PIN     "+bit+"\n")
		outfile.write("#define DIO"+pin+"_RPORT   PORT"+prt+"\n")
		outfile.write("#define DIO"+pin+"_WPORT   LAT"+prt+"\n")
		outfile.write("#define DIO"+pin+"_DDR     TRIS"+prt+"\n")
		outfile.write("#define DIO"+pin+"_DDRI    TRIS"+prt+"SET"+"\n")
		outfile.write("#define DIO"+pin+"_DDRO    TRIS"+prt+"CLR"+"\n")
		outfile.write("#define DIO"+pin+"_PWM     NULL\n"+"\n")

	# repeat while there is data

infile.close()
outfile.close()
