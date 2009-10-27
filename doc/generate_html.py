#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Class for generating HTML pages
#

#
# inputs:
# - Help directory with *.amih files
# - improcess_flex.lpp           --> tokens
# - improcess_bison.output      --> rules
# - improcess_bison.tab.cpp     --> rule documentation
# - improcess_html binary
# - directories Rules and Tokens

import string
from string import *
import os
import os.path
import sys
import re

print len(sys.argv)
print "\n"
if (len(sys.argv)<=1):
  print "No arguments\n"
  sys.exit(1)

improcess_flex_lpp      = "../src/Language/improcess_flex.lpp"
# try to replace improcess_html by a python script !!!
improcess_html          = "/home/karl/projects/Fluid/fluid/Karl/src/AMILab/Lex/improcess_html"
improcess_bison_output  = "../src/Language/improcess_bison.output"
improcess_bison_tab_cpp = "../src/Language/improcess_bison.tab.cpp"

scripts_path="../scripts/."

def get_tokens():
    lex_tokens={}
    f = open (improcess_flex_lpp, "r")
    fc = f.read()
    parse_token=re.compile('/\*\{.*,.*\}\*/')
    f.seek(0)
    #
    lines=split(fc,'\n')
    #
    for l in lines:
        t=parse_token.search(l)
        if t:
            values=split(t.group()[3:-3],',')
            lex_tokens[values[1]]=values[0]
            # now split expression and lex token:
    #print lex_tokens
    return lex_tokens

class Html_Page:

    def __init__ (self, t="", h=""):
        self.title = t
        self.heading = h
#        self.tabs       = ["tokens","variables","nodes","rules","scripts"]
        self.tabs       = ["tokens","rules","scripts"]
        self.tabs2   ={}
#        self.tabs2['tokens'] = ["alphabetic","topic"]
#        self.tabs2['rules']  = ["alphabetic","topic"]
        self.tabs2['tokens'] = []
        self.tabs2['rules']  = []
        self.html_tab ="    "
        self.html_currenttab = ""

    def generate_heading (self, bgcolor="", logo=""):
        #
        # Generate heading for a page
        #
        self.f.write ("<html>\n")
        self.f.write ("<head>\n")
        self.f.write ("<title>" + self.title + "</title>\n")
        # add style sheet ...
        self.f.write ('<link rel="stylesheet" '+
            'href="tabs.css"' +
        'type="text/css">\n')
        self.f.write ('<link href="documentstyle.css" rel="stylesheet" type="text/css" media="all" />\n')
        self.f.write ("</head>\n")
        self.f.write ("<body bgcolor=" + bgcolor + ">\n")
        self.f.write ("<h1 align=center>" + self.heading + "</h1>\n")
        if (logo!=""):
          self.f.write('<img src="%s">'%logo)

    def generate_tabs (self, prefix, tabs, current):
        if len(tabs)>0:
            self.file_write ('<div class="tabs">\n')
            self.file_write ("<ul>\n")
            self.html_inctab()
            for t in tabs:
                i=tabs.index(t)
                if i==current:
                    self.file_write('<li id="current"><a href=')
                else:
                    self.file_write("<li><a href=")
                self.file_write(prefix+tabs[i]+".html")
                self.file_write(' target="FBROWSE"><span>'+tabs[i]+"</span></a></li>\n")
            self.html_dectab()
            self.file_write("</ul>\n")
            self.file_write("</div><br>\n")
    
    def generate_alltabs (self, level1, level2):
      self.generate_tabs("",self.tabs,level1)
      if self.tabs[level1] in self.tabs2.keys():
        self.generate_tabs(self.tabs[level1]+"_",self.tabs2[self.tabs[level1]],level2)
    
    def generate_body (self):
	    #
	    # Empty function - to be redefined in a descendant
	    #
	    print ""

    def file_write(self,st):
      self.f.write(self.html_currenttab+st+"\n")

    def html_inctab(self):
      self.html_currenttab = self.html_currenttab+self.html_tab
    
    def html_dectab(self):
      self.html_currenttab = self.html_currenttab[:-len(self.html_tab)]

    def set_tokens(self,tokens,tokens_nolinks):
      self.tokens=tokens
      self.tokens_nolinks=tokens_nolinks
      self.tvalues=self.tokens.values()
      
    def set_commands(self,commands):
      self.commands=commands
      self.documented_commands = [ c[0] for c in self.commands]

    def set_rules(self,rules):
      self.rules=rules

    def set_nodes(self,nodes):
      self.nodes=nodes

    def set_scripts(self,scripts):
      self.scripts=scripts

    def html_token(self,token,parent=""):
        if token in self.tokens_nolinks:
          return token
        res=""
        res = res + '<a  href="%sTokens/%s_rules.html" target="FRULES" >'%(parent,token) +   '<span class="token">'+ token + '</span> </a>'
        if token in self.documented_commands:
            pos = self.documented_commands.index(token)
            res= res +' <a  href="' + parent+self.commands[pos][1] + '/' + self.commands[pos][0] + '.amih" target="FDOC" >'
            res = res+'<IMG SRC="'+parent+'book.gif" BORDER="0">'
            res = res+"</a>"
        return res
    
    def html_node(self,node,parent=""):
        res='<a  href="%srules.html#%s" target="FBROWSE" > %s </a>'%(parent,node,node)
        #res ='<span style="font-style: italic;">'+token+"</span>"
        #if token in self.documented_commands:
        #  res = res+"</a>"
        return res
    
    def add_tokens(self):
        #
        # sorted by command name
        #
        print "----------------"
        print "add_tokens"
        print "----------------\n"
        self.file_write ('<table width="550"  CELLSPACING=5>\n')
        self.html_inctab()
        self.file_write ("<dl compact='compact'>\n")
        i=0
        nb_columns=3
        width_str = "width=%d"%(100/nb_columns)
        tvaluescap = [ v.upper() for v in self.tvalues]
        tvaluescap_sorted=[ v.upper() for v in self.tvalues]
        tvaluescap_sorted.sort()
        for v in tvaluescap_sorted:
          print v
          if i%nb_columns ==0 :
            self.file_write('<tr>\n')
            self.html_inctab()
          self.file_write('<td '+width_str+'%>')
          # look for token in the list of commands
          initial_token=self.tvalues[tvaluescap.index(v)]
          self.file_write(self.html_token(initial_token))
          self.file_write ("</td>\n")
          i=i+1
          if i%nb_columns ==0 :
            self.html_dectab()
            self.file_write("</tr>\n")
        
        if i%nb_columns !=0:
            self.html_dectab()
            self.file_write("</tr>\n")
        self.html_dectab()
        self.file_write ("</table>\n")
        print "*** Done"
        
    def token_generate_rules(self,t):
        #f = open("Tokens/"+token+"_rules.html",w)
        # generate rules for this token
        self.file_write('<table>\n')
        for r in self.rules:
          if (t[0]!="'") and re.search(r'\b'+re.escape(t)+r'\b',r[2]):
            self.file_write('<tr valign=top align=left>\n')
            self.file_write('<td nowrap><font size=-1>(%3d) </font>'%(r[0]))
            if os.path.isfile("Rules/%d.txt"%r[0]):
              self.file_write('<a href="../Rules/%d.txt" target="FDOC"><IMG SRC="../book.gif" BORDER="0"></a>.'%(r[0]))
            self.file_write("</td><td nowrap>%s</td><td><--</td> </td>\n<td>%s</td>\n"%(r[1],self.translate_rule(r[2],"../")))
            self.file_write('</tr>')
        self.file_write('</table>')
    
    def translate_rule(self,rule,parent=""):
      #--- search for the tokens in the rule
      tr_rule=rule
      for t in self.tokens:
        if (t[0]!="'"):
          t1=r'\b'+re.escape(t)+r'\b'
        else:
          t1=re.escape(t)
        #print "%s %s %s \n"%(t1,lex_tokens[t],tr_rule)
        tr_rule=re.sub(t1,self.html_token(self.tokens[t],parent),tr_rule)
      # treat ',' apart for the moment
      tr_rule=re.sub(re.escape("','"),",",tr_rule)
      
      #--- search for nodes in the rule
      for n in self.nodes:
        n1=r'\b'+re.escape(n)+r'\b'
        tr_rule=re.sub(n1,self.html_node(n,parent),tr_rule)
      
      return tr_rule
    
    def add_rules(self):
        #
        # sorted by command name
        #
        self.file_write ('<table width="550"  CELLSPACING=3>\n')
        self.html_inctab()
        current_node=""
        for r in self.rules:
            if (r[1]!=current_node):
                current_node=r[1]
                print "adding "+current_node+"\n"
                self.file_write ('<td style="text-align: center;" colspan="1" rowspan="1"><a name="%s"></a><span style="font-weight: bold;">%s</span></td>\n'%(current_node,current_node)) 
            self.file_write('<tr>')
            self.html_inctab()
            #self.file_write('<td> %d </td> \t'%r[0])
            self.file_write('<td><font size=-1>(%3d) </font>'%(r[0]))
            if os.path.isfile("Rules/%d.txt"%r[0]):
              self.file_write('<a href="Rules/%d.txt" target="FDOC"><IMG SRC="book.gif" BORDER="0"></a>\n'%r[0])
            self.file_write(' %s \n'%(self.translate_rule(r[2])))
            self.file_write('</td> \n')
            self.html_dectab()
            self.file_write('</tr>')
        self.html_dectab()
        self.file_write ("</table>\n")
    
    
    def add_commands(self):
        #
        # sorted by command name
        #
        self.f.write ("<table >\n")
        self.f.write ("<dl compact='compact'>\n")
        for cmd,root in self.commands:
            self.f.write("<tr>\n")
            self.f.write ("<td><a  href=\""+root+"/"+cmd+".amih\">"+cmd+"</a></td>\n")
            self.f.write ("<td>"+root+"</td>\n")
        self.f.write("</tr>\n")
        self.f.write ("</table>\n")

    def add_commands2(self):
        #
        # sorted by directories
        #
        self.f.write ("<table >\n")
        self.f.write ("<dl compact='compact'>\n")
        for cmd,root in self.commands:
            self.f.write("<tr>\n")
            self.f.write ("<td>"+root+"</td>\n")
            self.f.write ("<td><a  href=\""+root+"/"+cmd+".amih\">"+cmd+"</a></td>\n")
        self.f.write("</tr>\n")
        self.f.write ("</table>\n")

    def add_scripts(self):
        #
        # sorted by command name
        #
        self.f.write ("<table >\n")
        self.f.write ("<dl compact='compact'>\n")
        for cmd,root in self.scripts:
            self.f.write("<tr>\n")
            self.f.write ("<td><a  href=\""+scripts_path+"/HTML/"+cmd+".amil.html\">"+cmd+"</a></td>\n")
            self.f.write ("<td>"+root+"</td>\n")
        self.f.write("</tr>\n")
        self.f.write ("</table>\n")

    def generate_trailer (self):
        #
        # generate the trailer for a page
        #
        self.f.write ("</body>\n")
        self.f.write ("</html>\n")
        self.f.close()
    
    def generate (self, bgcolor=""):
	    self.generate_heading (bgcolor)
	    self.generate_body ()
	    self.generate_trailer ()


class Main_Page (Html_Page):

    def __init__ (self, t="", h="",fname="index.html"):
	    Html_Page.__init__ (self, t,h)
	    self.f = open (fname, "w")
	    print "Authors page in--> " + self.f.name

#
# Code to test this class
#

import re

if __name__ == "__main__":

    #
    # Generate main page with frames
    #

    f = open ("amilab_help.html", "w")
    f.write('<HTML>')
    f.write('<HEAD>')
    f.write('<TITLE> AMILab Help </TITLE>')
    f.write('</HEAD>')
    f.write('<FRAMESET rows="140,1*">')
    f.write('  <FRAME SRC="title.html"   name="FTITLE" noresize >')
    f.write('  <FRAMESET cols="600,1*">')
    f.write('    <FRAME SRC="tokens.html" name="FBROWSE" noresize >')
    f.write('    <FRAMESET rows="150,1*">')
    f.write('      <FRAME SRC="test.amih"   name="FRULES">')
    f.write('      <FRAME SRC="test.amih"   name="FDOC">')
    f.write('    </FRAMESET>')
    f.write('  </FRAMESET>')
    f.write('</FRAMESET>')
    f.write('</HTML>')

    # title page
    p = Main_Page("AMILab Documentation", "<i>AMILAb documentation</i>",
                  "title.html")
    p.generate_heading ("white","logoami2.gif")
    p.generate_alltabs(0,0)
    p.generate_trailer ()
    
    #-------------------------------------------------
    # Alphabetic tokens
    #-------------------------------------------------

    
    p = Main_Page("List of tokens (keywords)", "<i>List of tokens (keywords)</i>",
                  "tokens.html")
    p.generate_heading ("white")
    #p.generate_tabs(0)
    p.generate_body ()
    amihfile=re.compile('\S*amih$')

    # 1. Create the table of contents from the main directories
    # 2. Propose also an alphabetical list

    print "** Processing Help directory:"
    commands=[]
    for root,dirs,files in os.walk("Help/."):
        #print dirs
        #print files
        for f in files:
            m=amihfile.match(f)
            if (m != None):
                cmd=string.split(m.group(),".amih")[0]
                print "  Adding  :"+cmd
                commands.append((cmd,root))
        #print commands
    commands.sort(lambda x, y: cmp(x[0].lower(), y[0].lower()))
    
    # get the list of tokens from the lex file
    lex_tokens=get_tokens()
    
    # save tokens strings for usage in C
    if (sys.argv[1]=="-tokens"):
        f = open ("token_list.h", "w")
        f.write("static const char* token_list[] = { ")
        for t in lex_tokens:
            if (upper(lex_tokens[t][0])>="A")&(upper(lex_tokens[t][0])<="Z"):
               f.write('\t'+ '"'+lex_tokens[t]+'", ')
        f.write("\t 0 };")
        sys.exit(0)
    
    lex_tokens_nolinks=['(',')','[',']',',','.','{','}']
    p.set_tokens(lex_tokens,lex_tokens_nolinks)
    p.set_commands(commands)
    p.add_tokens()
    p.generate_trailer ()

    #sys.exit(0)
    #-------------------------------------------------
    # Directories
    #-------------------------------------------------

    p = Main_Page("AMILab Documentation", "<i>html doc for AMILAb </i>",
                  "docamil_directories.html")
    p.generate_heading ("white")
    p.generate_body ()


    amihfile=re.compile('\S*amih$')

    # 1. Create the table of contents from the main directories
    # 2. Propose also an alphabetical list

    commands=[]

    for root,dirs,files in os.walk("Help/."):
        print dirs
        print files
        for f in files:
            m=amihfile.match(f)
            if (m != None):
                cmd=string.split(m.group(),".amih")[0]
                #print cmd
                commands.append((cmd,root))
                #print commands
    commands.sort(lambda x, y: cmp(x[1].lower(), y[1].lower()))
    p.set_commands(commands)
    p.add_commands2()
    p.generate_trailer ()


    #-------------------------------------------------
    # Scripts
    #-------------------------------------------------

    p = Main_Page("AMILab Documentation", "<i>html doc for AMILAb </i>",
                  "docamil_scripts.html")
    p.generate_heading ("white")
    p.generate_body ()


    amilfile=re.compile('\S*amil$')

    # 1. Create the table of contents from the main directories
    # 2. Propose also an alphabetical list

    scripts=[]

    import os

    for root,dirs,files in os.walk(scripts_path):
        print dirs
        print files
        for f in files:
            m=amilfile.match(f)
            if (m != None):
                cmd=string.split(m.group(),".amil")[0]
                #print cmd
                scripts.append((cmd,root))
                # generate html from the script
                scriptname    = root+"/"+cmd+".amil"
                scriptnewname = scripts_path+"/HTML/"+cmd+".amil"
                syscmd = improcess_html+ " " + \
                         scriptname + " > " + scriptnewname+".html"
                os.system(syscmd)
                #print commands
    scripts.sort(lambda x, y: cmp(x[0].lower(), y[0].lower()))
    p.set_scripts(scripts)
    p.add_scripts()
    p.generate_trailer ()

    #exit(0)

    #
    # Parsing rules
    #
    import re

    f = open (improcess_bison_output, "r")
    l=f.readline()
    while ((l.find('Gram')==-1)and(l.find('Grammar')==-1)):
        l=f.readline()
    # now the Grammar rules should start
    # and a number and the corresponding rule
    # after each empty line, new terminal

    def s_node(scanner, token): return token[:-1]
    def s_int(scanner, token):  return int(token) 
    def s_rule(scanner, token): return token[1:] 
    
    scanner_newnode = re.Scanner(  [ (r"\d+",s_int),
    (r"\s+", None),(r"[^\']*\:",s_node),(r"/\*.*\*/",None) ])
    scanner_newrule = re.Scanner( [ (r"\d+",s_int),
    (r"\s+", None),(r"\|.*",s_rule),(r"/\*.*\*/",None) ]) 
    scanner_newline = re.Scanner( [ (r"\s+", None) ]) 
    
    rule_number=0
    current_node=""
    new_node=1
    rules=[]
    nodes=[]
    
    while (rule_number>=0):
        l=f.readline()
        while (scanner_newline.scan(l)[1]==''):
            new_node=1
            l=f.readline()
        if (new_node==1):
            res=scanner_newnode.scan(l)
            if (res[0]!=[])and(res[0][0]==rule_number):
                current_node=res[0][1]
                nodes.append(current_node)
                current_rule=res[1]
                #print "rule %d found %s <-- %s "%(rule_number,current_node,current_rule)
                rules.append((rule_number,current_node,current_rule))
                rule_number=rule_number+1
            else:
                print "End of rules\n"
                rule_number=-1
            new_node=0
        else:
            res=scanner_newrule.scan(l)
            if (res[0]!=[])and(res[0][0]==rule_number):
                current_rule=res[0][1]
                rules.append((rule_number,current_node,current_rule))
                #print "rule %d found %s <-- %s "%(rule_number,current_node,current_rule)
                rule_number=rule_number+1
            else:
                print "End of rules\n"
                rule_number=-1
    
    #
    # Parsing rule documentation
    #
    import re

    if os.access("Rules",os.F_OK):
      # removing the files under the directory Rules
      for root, dirs, files in os.walk("Rules"):
        for name in files:
            os.remove(os.path.join(root, name))
      os.rmdir("Rules")
    os.mkdir("Rules")
    f = open (improcess_bison_tab_cpp, "r")
    
    # delete current rules
    
    l=f.readline()
    while (l):
        res=re.search(r"case (?P<int>\d+):", l)
        if res:
          # for some reason, we need to substract 1 to get the real rule number
          rule_number=int(res.group("int"))-1
          #print rule_number; print "\t"
          # looking for documentation in the code
          l=f.readline()
          res=re.search(r"case (?P<int>\d+):", l)
          while l and not(res):
            doc=re.search(re.escape("/**"),l)
            if doc:
              # read until the end
              print "rule %d %s = %s \n"%(rule_number,rules[rule_number][1],rules[rule_number][2])
              # creating first documentation file
              frule = open("Rules/%d.txt"%rule_number,"w")
              enddoc=re.search(re.escape("**/"),l)
              while l and not(enddoc):
                frule.write(l)
                l=f.readline()
                enddoc=re.search(re.escape("**/"),l)
              frule.write(l)
              frule.close()
            l=f.readline()
            res=re.search(r"case (?P<int>\d+):", l)
        else:
          l=f.readline()

    print "end\n"
    
    
    #
    # create list of rules per token
    #
    if os.access("Tokens",os.F_OK):
      # removing the files under the directory Tokens
      for root, dirs, files in os.walk("Tokens"):
        for name in files:
            os.remove(os.path.join(root, name))
      os.rmdir("Tokens")
    os.mkdir("Tokens")
    for t in lex_tokens:
      # exclude tokens with special characters
      if (t[0]!="'"):
        print "creating page for "+lex_tokens[t]+"\n"
        p = Main_Page("rules for "+lex_tokens[t], "<i>rules using %s</i>"%lex_tokens[t],
                    "Tokens/"+lex_tokens[t]+"_rules.html")
        p.generate_heading ("white")
        p.generate_body ()
        p.set_tokens(lex_tokens,lex_tokens_nolinks)
        p.set_commands(commands)
        p.set_rules(rules)
        p.set_nodes(nodes)
        p.token_generate_rules(t)
        p.generate_trailer ()
    
    #
    # create the file rules.html
    #
    p = Main_Page("List of rules", "<i>List of rules</i>",
                  "rules.html")
    p.generate_heading ("white")
    #p.generate_tabs(0)
    p.generate_body ()
    amihfile=re.compile('\S*amih$')

    p.set_tokens(lex_tokens,lex_tokens_nolinks)
    p.set_commands(commands)
    p.set_rules(rules)
    p.set_nodes(nodes)
    

    p.add_rules()
    p.generate_trailer ()

    