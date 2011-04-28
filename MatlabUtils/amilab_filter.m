function res=amilab_filter(im,std,xorder,yorder)
%
% calls the amilab filter command
%
  mydocdir='C:\Users\Karl\Documents\';
  inputfilename=sprintf('%s%s',mydocdir,'amilab_filter_input.ami');
  outputfilename=sprintf('%s%s',mydocdir,'amilab_filter_output.ami');
  writeami(im,inputfilename);
  cd('C:\Program Files\AMILab_3.1.0\bin')
  amilab_cmdline='amilab_3.1.0.exe';
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,'C:\Users\Karl\Documents\runfilter.amil');
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,inputfilename);
  amilab_cmdline=sprintf('%s %f',amilab_cmdline,std);
  amilab_cmdline=sprintf('%s %d',amilab_cmdline,xorder);
  amilab_cmdline=sprintf('%s %d',amilab_cmdline,yorder);
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,outputfilename);
  system(amilab_cmdline);
  res = readami(outputfilename);
  