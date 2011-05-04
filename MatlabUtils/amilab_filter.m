function res=amilab_filter(im,std,xorder,yorder)
%
% calls the amilab filter command
%
  global amilab_tmpdir
  global amilab_bindir
  global amilab_bin

  inputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_input.ami');
  outputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_output.ami');
  writeami(im,inputfilename);
  cd(amilab_bindir)
  amilab_cmdline=amilab_bin;
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,'BasicFilters/GaussianFilter/GaussianFilterRun.amil');
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,inputfilename);
  amilab_cmdline=sprintf('%s %f',amilab_cmdline,std);
  amilab_cmdline=sprintf('%s %d',amilab_cmdline,xorder);
  amilab_cmdline=sprintf('%s %d',amilab_cmdline,yorder);
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,outputfilename);
  system(amilab_cmdline);
  res = readami(outputfilename);
  