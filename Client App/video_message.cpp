//#include "video_message.h"
//
//video_message::Vid_status video_message::Record_Live_Video(int frame_rate)
//{
//	if (video_recorded)
//		return Vid_Error;
//	cv::VideoCapture capt(0);	//open default webcam 0
//	if (!capt.isOpened())
//		return Vid_Error;
//	int frame_width = static_cast<int>(capt.get(cv::CAP_PROP_FRAME_WIDTH));
//	int frame_height = static_cast<int>(capt.get(cv::CAP_PROP_FRAME_HEIGHT));
//	cv::VideoWriter videoWriter("path/to/your/directory/output_video.avi",
//		cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), // codec
//		30, // frame rate
//		cv::Size(frame_width, frame_height));
//	return Vid_status();
//}
