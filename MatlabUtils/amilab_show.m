function res=amilab_show(im)
%
% calls the amilab filter command
%
  global amilab_tmpdir
  global amilab_bindir
  global amilab_bin

  inputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_input.ami');
  writeami(im,inputfilename);
  cd(amilab_bindir)
  amilab_cmdline=amilab_bin;
  %amilab_cmdline=sprintf('%s %s',amilab_cmdline,'-hide');
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,'Visualization/ImageViewerRun.amil');
  amilab_cmdline=sprintf('%s %s',amilab_cmdline,inputfilename);
  system(amilab_cmdline);
  