import os
import re
	
def get_unordered_start(fullMarkupFile, unorderedListStartRegex):
	#Returns a list containing start locations of all unordered lists
	
	startLocations=[]
	unorderedListIterator= unorderedListStartRegex.finditer(fullMarkupFile)
	for nextLocation in unorderedListIterator:
		startLocations.append(nextLocation.start())
	
	return startLocations
		
def get_unordered_end(fullMarkupFile, unorderedListEndRegex):
	#Returns a list containing end locations of all unordered lists
	
	endLocations=[]
	unorderedListIterator= unorderedListEndRegex.finditer(fullMarkupFile)
	for nextLocation in unorderedListIterator:
		endLocations.append(nextLocation.end())
	
	return endLocations

def get_ordered_start(fullMarkupFile, orderedListStartRegex):
	#Returns a list containing start locations of all ordered lists
	
	startLocations=[]
	orderedListIterator= orderedListStartRegex.finditer(fullMarkupFile)
	for nextLocation in orderedListIterator:
		startLocations.append(nextLocation.start())
	
	return startLocations
		
def get_ordered_end(fullMarkupFile, orderedListEndRegex):
	#Returns a list containing end locations of all ordered lists
	
	endLocations=[]
	orderedListIterator= orderedListEndRegex.finditer(fullMarkupFile)
	for nextLocation in orderedListIterator:
		endLocations.append(nextLocation.end())
	
	return endLocations


def main():
	#Prompt user for a markup file to be converted to html
	markupFile = input("Enter path for markup file: ")
	htmlOutFile= open("test.html", 'w')
	fullMarkup= ""
	htmlOut= ""
	
	if not os.path.exists(markupFile):
		print("\nSORRY, the file", markupFile, "does not exist.")
		print("Try another filename ...")
	else:
		INPUT = open(markupFile, 'r')
		
		name= markupFile.split('/')
		
		#Write the beginning of the html document using the name of the markup file as the name of the page	
		htmlOutFile.write("<!DOCTYPE html>"+"\n")
		htmlOutFile.write("<html>"+"\n")
		htmlOutFile.write(name[-1]+"\n")
		htmlOutFile.write("<body>"+"\n")
		
		fullMarkupFile=""
		
		#store all of markup file in a single string	
		for line in INPUT:
			fullMarkupFile=fullMarkupFile+line
		
		#sub out markup paragraph start for html paragraph start	
		paragraphStartRegex= re.compile(r"!b")
		fullMarkupFile=re.sub(paragraphStartRegex,"<p>",fullMarkupFile)
			
		#sub out markup paragraph end for html paragraph end	
		paragraphEndRegex= re.compile(r"!e")
		fullMarkUpFile=re.sub(paragraphEndRegex,"</p>",fullMarkupFile)
			
		#sub out markup heading1 start for html heading1 start	
		heading1StartRegex= re.compile(r"=b")
		fullMarkupFile=re.sub(heading1StartRegex,"<H1>",fullMarkupFile)
		
		#sub out markup heading1 end for html heading1 end
		heading1EndRegex= re.compile(r"=e")
		fullMarkupFile=re.sub(heading1EndRegex,"</H1>",fullMarkupFile)
		
		#sub out markup heading2 start for html heading2 start
		heading2StartRegex= re.compile(r"-b")
		fullMarkupFile=re.sub(heading2StartRegex,"<H1>",fullMarkupFile)
		
		#sub out markup heading2 end for html heading2 end		
		heading2EndRegex= re.compile(r"-e")
		fullMarkupFile=re.sub(heading2EndRegex,"</H1>",fullMarkupFile)
		
		#sub out markup code start for html code start
		codeStartRegex= re.compile(r"c_b")
		fullMarkupFile= re.sub(codeStartRegex,"<code>" ,fullMarkupFile)		
		
		#sub out markup code end for html code end
		codeEndRegex= re.compile(r"c_e")		
		fullMarkupFile= re.sub(codeEndRegex,"</code>" ,fullMarkupFile)
		
		'''This does not work
		unorderedListStartRegex= re.compile(r"%b")
		fullMarkupFile=re.sub(unorderedListStartRegex, "<ul>", fullMarkupFile)
		
		unorderedListEndRegex= re.compile(r"%e")
		fullMarkupFile=re.sub(unorderedListStartRegex, "</ul>", fullMarkupFile)		
		
		ulStartLocations=get_unordered_start(unorderedListStartRegex, fullMarkupFile)
		ulEndLocations=get_unordered_end(unorderedListEndRegex, fullMarkupFile)
		
		i=0
		addToFullMarkup=[]
		for aLocation in ulStartLocations:
			
			for line in fullMarkupFile[ulStartLocations[i]:ulEndLocations[i]]:
				if line[0]=="%":
					addToFullMarkup.append(line)
				else:
					line= "<li>"+line+"</li>"
					addToFullMarkup.append(line)
			i+=1
				
				
		j=0                            
		for aLocation in ulStartLocations:
			fullMarkupFile=fullMarkupFile.replace(fullMarkupFile[ulStartLocations[j]:ulEndLocations[j]],addToFullMarkup[j],1)
			j+=1
		'''
		
		'''This does not work
		orderedListStartRegex= re.compile(r"+b")
		fullMarkupFile=re.sub(unorderedListStartRegex, "<ul>", fullMarkupFile)
				
		orderedListEndRegex= re.compile(r"+e")
		fullMarkupFile=re.sub(unorderedListStartRegex, "</ul>", fullMarkupFile)		
		
		olStartLocations=get_ordered_start(orderedListStartRegex, fullMarkupFile)
		olEndLocations=get_ordered_end(orderedListEndRegex, fullMarkupFile)
		
		k=0
		addToFullMarkup2=[]
		for aLocation in olStartLocations:
			
			for line in fullMarkupFile[olStartLocations[k]:olEndLocations[k]]:
				if line[0]=="+":
					addToFullMarkup.append(line)
				else:
					line= "<li>"+line+"</li>"
					addToFullMarkup.append(line)
			k+=1
				
				
		l=0                            
		for aLocation in olStartLocations:
			fullMarkupFile=fullMarkupFile.replace(fullMarkupFile[olStartLocations[l]:olEndLocations[l]],addToFullMarkup[l],1)		
			l+=1
		'''
		#sub out markup blockquote start for html blockquote start
		blockQuoteStartRegex= re.compile(r">b")
		fullMarkupFile=re.sub(blockQuoteStartRegex, "<blockquote> <p>", fullMarkupFile)
		
		#sub out markup blockquote end for html blockquote end
		blockQuoteEndRegex= re.compile(r">e")
		fullMarkupFile=re.sub(blockQuoteEndRegex, "</p> </blockquote>", fullMarkupFile)		
		
		#sub out markup image start for html image start
		imgStartRegex= re.compile(r"img_b\n")
		fullMarkupFile= re.sub(imgStartRegex,"<img src=\"" ,fullMarkupFile)		
		
		#sub out markup image end for html image end
		imgEndRegex= re.compile(r"img_e\n")
		fullMarkupFile= re.sub(imgEndRegex,"\" />" ,fullMarkupFile)
		
		#sub out markup hyperlink start for html hyperlink start
		hyperlinkStartRegex= re.compile(r"l_")
		fullMarkupFile= re.sub(hyperlinkStartRegex,"<a" ,fullMarkupFile)
		
		#sub out markup hyperlink end for html hyperlink end
		hyperlinkEndRegex= re.compile(r"_l")		
		fullMarkupFile= re.sub(hyperlinkEndRegex,"> </a>" ,fullMarkupFile)		
		