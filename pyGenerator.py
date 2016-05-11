#!/usr/bin/python

import sys

JavaData = {
	'Lang_id' : 'JAVA',
	'Source Extension':'.java',
	'Single-Line Comment' : '//',
	'Multi-Line Comment' : ['/*','*/'],
	'Libraries' : [],
	'Constants' : []	
}

CPPData = {
	'Lang_id' : 'C++11',
	'Single-Line Comment' : '//',
	'Multi-Line Comment' : ['/*','*/'],
	'Source Extension' : '.cpp',
	'Library Get' : '#include',
	'Constant Def' : '#define',
	'Functions' : {
		'Main' : 'int main(int argc, char* argv[])'
	},
	'Libraries' : ['iostream','vector','cmath','fstream','deque','string','algorithm','cstdio','cstdlib','ctime'],
	'Constants' : [['BUFFER','1024'],['PI','3.14159265359']]
}

PythonData = {
	
}

FortranData = {
	
}

PascalData = {
	
}



class Impresion(object):

	def generateUserData(self):
		file = open(self.filename,'a')
		file.write(self.data['Multi-Line Comment'][0]+'\n')
		file.write('HOLA\n')
		file.write(self.data['Multi-Line Comment'][1]+'\n')
		file.close()

	def generateLibraries(self):
		pass

	def generateConstants(self):
		pass

	def generatefile(self):
		# Fill USACO user Data
		self.generateUserData()
		# Generate Libraries
		self.generateLibraries()
		# Generate Constants
		self.generateConstants()

	def __init__(self, idprog, prog, filename,lang):
		self.id = idprog
		self.prog = prog
		
		if (
			lang == 'c++' or lang == 'C++' or
			lang == 'cpp' or lang == 'CPP' or
			lang == 'c' or lang == 'C' or
			lang == 'c++11' or lang == 'C++11' or
			lang == 'cpp11' or lang == 'CPP11'
			):
			self.data = CPPData
		elif (
			lang == 'java' or lang == 'JAVA' or
			lang == 'Java'
			):
			self.data = JavaData
		elif (
			lang == 'Python' or lang == 'PYTHON' or
			lang == 'python'
			):
			self.data = PythonData
		elif (
			lang == 'Fortran' or lang == 'fortran'
			):
			self.data = FortranData
		elif (
			lang == 'Pascal' or lang == 'PASCAL'
			):
			self.data = PascalData
		else:
			raise 'Language error.'
		self.filename = filename+self.data['Source Extension']

def main(argv):
	if len(argv) == 4:
		print 'ID: ' + argv[0]
		print 'PROG: ' + argv[1]
		print 'LANGUAGE: ' + argv[3]
		print 'Output code file: ' + argv[2]
		file = Impresion(argv[0],argv[1],argv[2],argv[3])
		file.generatefile()
	else:
		print 'Error: Not enough arguments!'
		print 'Usage: (program) ID PROGRAM FILENAME'
		print 'ID       - The ID USACO Training Gate gave you.'
		print 'PROGRAM  - The Program you\'re solving.'
		print 'FILENAME - The Filename you wish to be generated WITHOUT EXTENSION.'
		

if __name__ == '__main__':
	main(sys.argv[1:])