/** @file
@brief Face segmentation utility functions.
*/

#ifndef __FACE_SEG_UTILITIES__
#define __FACE_SEG_UTILITIES__

// OpenCV
#include <opencv2/core.hpp>

namespace face_seg
{
	/** Render segmentation blended with image
	@param img The image that the segmentation will be blended with.
	@param seg The segmentation as an 8-bit image.
	@param alpha Blending weight [0, 1].
	0 means completely transparent and 1 means completely opaque.
	@param color The color to blend with.
	*/
	void renderSegmentationBlend(cv::Mat& img, const cv::Mat& seg, float alpha = 0.5f,
		const cv::Scalar& color = cv::Scalar(0, 0, 255));

	void removeSmallerComponents(cv::Mat& seg);

	void smoothFlaws(cv::Mat& seg, int smooth_iterations = 1, int smooth_kernel_radius = 2);

	void fillHoles(cv::Mat& seg);

	void postprocessSegmentation(cv::Mat& seg, bool disconnected = true,
		bool holes = true, bool smooth = true, int smooth_iterations = 1,
		int smooth_kernel_radius = 2);

}   // namespace face_seg

#endif	// __FACE_SEG_UTILITIES__
