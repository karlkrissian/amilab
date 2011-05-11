function res=amilab_filtercommand(im,cmd,interact,display)
%
% calls an amilab command to process the input image im and return the processed image
% the image in the command is called 'i'
% if the command contains the keyword 'return', it is interpreted as the body of an amilab function and can
% include several commands separated by ; or newline.
% Parameters:
%   - input image
%   - commands to execute in amilab as a string
%   - interact: 0 or 1 depending if we want user interaction in amilab or
%   not
%   - display: 0 or 1, if we want to display the result in matlab or not
%
  amilab_setup()
  global amilab_tmpdir
  global amilab_bindir
  global amilab_bin

  if ~exist('interact','var')
    interact=0
  end

  inputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_input.ami');
  outputfilename=sprintf('%s%s',amilab_tmpdir,'amilab_filter_output.ami');
  writeami(im,inputfilename);
  cd(amilab_bindir)
  amilab_cmdline=amilab_bin;
  if ~interact
    amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,'-hide');
    amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,'-quit');
  end
  amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,'Utils/ImageFilterRun.amil');
  amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,inputfilename);
  amilab_cmdline=sprintf('%s "%s"',amilab_cmdline,cmd);
  amilab_cmdline=sprintf('%s %s'  ,amilab_cmdline,outputfilename);
  if interact
    amilab_cmdline=sprintf('%s &'  ,amilab_cmdline);
  end
  system(amilab_cmdline);
  res = readami(outputfilename);
  if exist('display','var') 
    if display
      figure
      subplot(1,2,1),imshow(im,[]);
      subplot(1,2,2),imshow(res,[]);
    end
  end
  