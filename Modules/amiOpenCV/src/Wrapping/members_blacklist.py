
members_blacklist=[
   "cv::Mat::ptr", # ambiguity in returning type
   "cv::Mat::ptr<int>", # template member, not well implemented I suppose
   "cv::Mat::zeros(int, int const*, int)", # not implemented !!!
   "cv::Mat::ones(int, int const*, int)", # not implemented !!!
   "cv::Vec<float, 3>::conj", # probably not implemented
]
