function res=amilab_filtercommand(im,cmd,display)
%
% calls an amilab command to process the input image im and return the processed image
% the image in the command is called 'i'
% if the command contains the keyword 'return', it is interpreted as the body of an amilab function and can
% include several commands separated by ; or newline.
% 
%
  amilab_setup()
  global amilab_tmpdir
  global amilab_bindir
  global amilab_bin

  inputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_input.ami');
  outputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_output.ami');
  writeami(im,inputfilename);
  cd(amilab_bindir)
  amilab_cmdline=amilab_bin;
  amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,'-hide');
  amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,'Utils/ImageFilterRun.amil');
  amilab_cmdline=sprintf('%s "%s"',amilab_cmdline,cmd);
  amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,outputfilename);
  system(amilab_cmdline);
  res = readami(outputfilename);
  if display
      figure(),imshow(res,[]);
  end
  