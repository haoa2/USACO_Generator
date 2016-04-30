#!/usr/bin/python

import sys

class Impresion(object):
	libraries = ['iostream','vector','cmath','fstream','deque','string','algorithm','cstdio','cstdlib','ctime']
	constants = [['BUFFER','1024'],['PI','3.14159265359']]

	def generatefile(self):
		f = open(self.filename+'.cpp','a')

		# Fill USACO user Data
		f.write('/*\nID: '+self.id+'\n')
		f.write('PROG: '+self.prog+'\n')
		f.write('LANG: C++11\n*/\n')

		# Generate Libraries
		f.write('\n// Libraries\n')
		for library in self.libraries:
			f.write('#include <'+library+'>\n')

		# Generate Constants
		f.write('\n// Constants\n')
		for constant in self.constants:
			f.write('#define '+constant[0]+' '+constant[1]+'\n')

		f.write('\n// Function Templates\n\n')
		f.write('\n// Main Function\n')
		f.write('int main(int argc, char* argv[])\n{\n')
		f.write('\t// Input & Output\n')
		f.write('\tstd::ofstream fout("'+self.prog+'.out",std::ios::out);\n')
		f.write('\tstd::ifstream fin("'+self.prog+'.in",std::ios::in);\n')
		f.write('\n\t// Rest of Main\n\n\n')
		f.write('\treturn 0; // Exit Success.\n')
		f.write('}\n\n')
		f.write('// Functions Implementations\n')

		f.write('\n// Template created by: Humberto Alejandro Ortega Alcocer <humbertowoody@gmail.com>')
		pass

	def __init__(self, idprog, prog, filename):
		self.id = idprog
		self.prog = prog
		self.filename = filename


def main(argv):
	if len(argv) == 3:
		print 'ID: ' + argv[0]
		print 'PROG: ' + argv[1]
		print 'Output code file: ' + argv[2]
		file = Impresion(argv[0],argv[1],argv[2])
		file.generatefile()
	else:
		print 'Error: Not enough arguments!'
		print 'Usage: (program) ID PROGRAM FILENAME'
		print 'ID       - The ID USACO Training Gate gave you.'
		print 'PROGRAM  - The Program you\'re solving.'
		print 'FILENAME - The Filename you wish to be generated WITHOUT EXTENSION.'
		

if __name__ == '__main__':
	main(sys.argv[1:])