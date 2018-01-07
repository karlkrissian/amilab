#include <windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>

#ifndef _USE_OLD_IOSTREAMS

using namespace std;

#endif

// maximum mumber of lines the output console should have

static const WORD MAX_CONSOLE_LINES = 500;
static std::streambuf *coutbuf;

#ifdef WIN32

void RedirectIOToFile()
{
  std::ofstream out("out.txt");
  coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
}

void ResetIO()
{
  std::cout.rdbuf(coutbuf); //reset to standard output again
}

void RedirectIOToConsole()
{

int hConHandle;
HANDLE lStdHandle;

CONSOLE_SCREEN_BUFFER_INFO coninfo;
FILE *fp;
// allocate a console for this app
AllocConsole();
// set the screen buffer to be big enough to let us scroll text
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&coninfo);
coninfo.dwSize.Y = MAX_CONSOLE_LINES;
SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coninfo.dwSize);

// redirect unbuffered STDOUT to the console
lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
hConHandle = _open_osfhandle((intptr_t)lStdHandle, _O_TEXT);
fp = _fdopen( hConHandle, "w" );
*stdout = *fp;
setvbuf( stdout, NULL, _IONBF, 0 );

// redirect unbuffered STDIN to the console
lStdHandle = GetStdHandle(STD_INPUT_HANDLE);
hConHandle = _open_osfhandle((intptr_t)lStdHandle, _O_TEXT);
fp = _fdopen( hConHandle, "r" );
*stdin = *fp;
setvbuf( stdin, NULL, _IONBF, 0 );

// redirect unbuffered STDERR to the console
lStdHandle = GetStdHandle(STD_ERROR_HANDLE);
hConHandle = _open_osfhandle((intptr_t)lStdHandle, _O_TEXT);
fp = _fdopen( hConHandle, "w" );
*stderr = *fp;
setvbuf( stderr, NULL, _IONBF, 0 );

// makestd::cout, wcout, cin, wcin, wcerr, std::cerr, wclog and clog
// point to console as well
ios::sync_with_stdio();
}

#endif
//End of File

 
