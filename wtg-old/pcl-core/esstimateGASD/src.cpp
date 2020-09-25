#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/features/gasd.h>


int
main (int argc, char** argv)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  for (std::size_t i = 0; i < cloud->points.size (); ++i)
    std::cout << "    " << cloud->points[i].x
              << " "    << cloud->points[i].y
              << " "    << cloud->points[i].z << std::endl;




      // Create the GASD estimation class, and pass the input dataset to it
  pcl::GASDEstimation<pcl::PointXYZ, pcl::GASDSignature512> gasd;
  gasd.setInputCloud (cloud);

  // Output datasets
  pcl::PointCloud<pcl::GASDSignature512> descriptor;

  // Compute the descriptor
  gasd.compute (descriptor);

  // Get the alignment transform
  Eigen::Matrix4f trans = gasd.getTransform (trans);

  // Unpack histogram bins
  for (std::size_t i = 0; i < std::size_t( descriptor[0].descriptorSize ()); ++i)
  {
    descriptor[0].histogram[i];
  }

  return (0);
}

