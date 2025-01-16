//#pragma once
//#include <string>
//#include <filesystem>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/core/mat.hpp>
//#include <opencv2/highgui.hpp>
//#include "message.h"
//class video_message : public message
//{
//private:
//	std::string vid_name;
//	std::filesystem::path vid_send_path;	//video path at sender side for pre-recorded videos
//	std::filesystem::path vid_show_path;	//video path at receiver side
//	bool video_recorded;	//Video type whether pre-recorded or live webcam video, 0=live webcam, 1=pre-recorded
//	bool temp_vid;	//flag to indicate whether a temporary video or not
//	cv::Mat Live_Video_Matrix;
//
//public:
//	enum Vid_status { Vid_OK, Vid_noexist, Vid_Error };	//Videos show status
//	video_message() = delete;	//deleted default constructor
//	video_message(message_type msg_t,unsigned long long v_senderid,std::string v_sender,std::string v_sendername,std::string name,
//		std::filesystem::path full_path,bool vid_type,bool temp) //Parameterized constructor for original messages
//		:message(msg_t, v_senderid, v_sender, v_sendername),
//		vid_name(name),
//		vid_send_path(full_path),
//		video_recorded(vid_type),
//		temp_vid(temp){}
//	video_message(const video_message&);	//copy constructor
//	video_message(video_message&&);	//move constructor
//	~video_message() = default;
//
//	inline void Set_ShowPath(std::filesystem::path show_directory)
//	{
//		vid_show_path = show_directory / vid_name;
//	}
//	inline std::filesystem::path Get_SendPath(void)
//	{
//		return vid_send_path;
//	}
//
//	Vid_status Record_Live_Video(int frame_rate);
//	Vid_status Show_Video(void);
//
//
//
//
//
//};
//
