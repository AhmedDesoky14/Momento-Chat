/************************************************************************************************************************
 * 	Module: image message class
 * 	File Name: image:message.cpp
 *  Authors: Ahmed Desoky
 *	Date: 2/11/2024
 *	*********************************************************************************************************************
 *	Description: image message class to deal with images messages creation preview
 *				 it supports both temporary images and permenantely stored images
 ***********************************************************************************************************************/
/***********************************************************************************************************************
*                     							 Header Files Included
***********************************************************************************************************************/
#include "image_message.h"
#include "platform_conf.h"

#if(PLATFORM == LINUX)
#include <X11/Xlib.h>
#elif(PLATFORM == WINDOWS)

#endif
/***********************************************************************************************************************
*                     					    Member Functions Implementation
***********************************************************************************************************************/
/************************************************************************************************************************
* Function: Copy constructor
* Function ID[hex]: 0x00
* Parameters (in):  object to be copied
* Parameters (out): NONE - constructor
* Return value: NONE - constructor
* Description: Copy constructor that creates copy of an image message
************************************************************************************************************************/
image_message::image_message(const image_message& obj_copy)
    :message(obj_copy.msg_type,obj_copy.sender,obj_copy.sender_name,obj_copy.GMT_time),
    img(obj_copy.img),
    img_name(obj_copy.img_name),
    img_send_path(obj_copy.img_send_path),
    temp_img(obj_copy.temp_img),
    img_time_s(obj_copy.img_time_s)
{}
/************************************************************************************************************************
* Function: Move constructor
* Function ID[hex]: 0x01
* Parameters (in):  object to be moved
* Parameters (out): NONE - constructor
* Return value: NONE - constructor
*Description: Move constructor that moves ownership of a message
************************************************************************************************************************/
image_message::image_message(image_message&& obj_move)
    :message(obj_move.msg_type, obj_move.sender, obj_move.sender_name, obj_move.GMT_time),
    img(obj_move.img),
    img_name(obj_move.img_name),
    img_send_path(obj_move.img_send_path),
    temp_img(obj_move.temp_img),
    img_time_s(obj_move.img_time_s)
{
    obj_move.GMT_time = nullptr;
}
/************************************************************************************************************************
* Function: Show_Image
* Function ID[hex]: 0x04
* Parameters (in):  NONE
* Parameters (out): NONE
* Return value: Image show status
* Description: Function to show the image and only if it's not temporary save it in save directory before it
*              This function has dependency on the platform type
************************************************************************************************************************/
image_message::Img_status image_message::Show_Image(std::filesystem::path save_directory)
{
#if(PLATFORM == LINUX)
    //Display* display = XOpenDisplay(nullptr);
    //if (display == nullptr)
    //    return Img_Error;
    //Screen* screen = DefaultScreenOfDisplay(display);
    //if (screen == nullptr)
    //    return Img_Error;
#elif(PLATFORM == WINDOWS)




#endif
	//cv::Mat img = cv::imread(img_show_path,cv::IMREAD_UNCHANGED);
    if (img.empty())
        return Img_noexist;
    cv::namedWindow(img_name,cv::WINDOW_NORMAL);
    //cv::resizeWindow(img_name,screen->width,screen->height);
    cv::resizeWindow(img_name,1400,900);
    imshow(img_name,img);
    if (temp_img)
    {
        cv::waitKey(img_time_s * 1000);
        //std::filesystem::remove(img_show_path);
        //img_show_path.clear();
        img_name.clear();
    }
    else
    {
        std::filesystem::path save_file_path = save_directory / img_name;
        if(!cv::imwrite(save_file_path,img))
        {
            return Img_Error;   //if error occured during saving the image
        }
        cv::waitKey(0);
    }
    return Img_OK;
}
