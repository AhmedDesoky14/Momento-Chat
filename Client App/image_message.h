/************************************************************************************************************************
 * 	Module: image message class
 * 	File Name: image:message.h
 *  Authors: Ahmed Desoky
 *	Date: 2/11/2024
 *	*********************************************************************************************************************
 *	Description: image message class to deal with images messages creation preview
 *				 it supports both temporary images and permenantely stored images
 ***********************************************************************************************************************/
 /***********************************************************************************************************************
 *                     							 Header Files Included
 ***********************************************************************************************************************/
#pragma once
#include "message.h"
#include <filesystem>
//#include <opencv2/opencv.hpp>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
class image_message : public message
{
/***********************************************************************************************************************
*                     								Private Members
***********************************************************************************************************************/
private:
	cv::Mat img;
	std::string img_name;
	std::filesystem::path img_send_path;	//image path at sender side
	std::filesystem::path save_path;	//image path at receiver side
	bool temp_img;	//flag to indicate whether a temporary image or not
	unsigned int img_time_s;	//if temporary image, specify the time of image preview
/***********************************************************************************************************************
*                     								Public Members
***********************************************************************************************************************/
public:
	enum Img_status { Img_OK,Img_noexist,Img_Error};	//images show status
	image_message() = delete;	//deleted default constructor
	image_message(message_type msg_t, std::pair<unsigned long long, std::string> sender, std::string v_sendername, std::string name,
		std::filesystem::path full_path, bool temp, unsigned int time_s) //Parameterized constructor for original messages
		:message(msg_t, sender, v_sendername),
		img_name(name),
		img_send_path(full_path),
		temp_img(temp),
		img_time_s(time_s)
	{img = cv::imread(img_send_path,cv::IMREAD_UNCHANGED);}
	image_message(const image_message&);	//copy constructor
	image_message(image_message&&);	//move constructor
	~image_message() = default;
/************************************************************************************************************************
* Function: Parametrized Constructor
* Function ID[hex]: 0x02
* Parameters (in):  NONE
* Parameters (out): image send path
* Return value: image send path
* Description: inline function to get the image sent path
************************************************************************************************************************/
	inline std::filesystem::path Get_SendPath(void) const
	{
		return img_send_path;
	}
/************************************************************************************************************************
* Function: Get_Image_Matrix
* Function ID[hex]: 0x03
* Parameters (in):  NONE
* Parameters (out): image matrix
* Return value: image matrix
* Description: inline function to get image matrix
************************************************************************************************************************/
	inline cv::Mat Get_ImageMatrix(void) const
	{
		return img;
	}
/************************************************************************************************************************
* Function: Check_ImageMatrix
* Function ID[hex]: 0x04
* Parameters (in):  NONE
* Parameters (out): images status
* Return value: images status
* Description: inline function to check if image is loaded or not
************************************************************************************************************************/
	inline Img_status Chek_ImageMatrix(void) const
	{
		if (img.empty())
			return Img_noexist;
		return Img_OK;
	}
	
	Img_status Show_Image(std::filesystem::path save_directory);
};

