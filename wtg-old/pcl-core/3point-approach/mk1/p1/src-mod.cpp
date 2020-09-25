#include <iostream>
#include <vector>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h>
#include <pcl/segmentation/region_growing.h>



#include <pcl/pcl_base.h>



int
main (int argc, char** argv)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  if ( pcl::io::loadPCDFile <pcl::PointXYZ> ("test.pcd", *cloud) == -1)
  {
    std::cout << "Cloud reading failed." << std::endl;
    return (-1);
  }


  // PREPROCESSING -------------------------------------------------------------------------------------

  pcl::search::Search<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
  pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
  normal_estimator.setSearchMethod (tree);
  normal_estimator.setInputCloud (cloud);
  normal_estimator.setKSearch (50);
  normal_estimator.compute (*normals);

  pcl::IndicesPtr indices (new std::vector <int>);
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (0.0, 1.0);
  pass.filter (*indices);


  // CALCULATING CLUSTERS -------------------------------------------------------------------------------------------

  pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
  reg.setMinClusterSize (50);
  reg.setMaxClusterSize (1000000);
  reg.setSearchMethod (tree);
  reg.setNumberOfNeighbours (30);
  reg.setInputCloud (cloud);
  //reg.setIndices (indices);
  reg.setInputNormals (normals);
  reg.setSmoothnessThreshold (3.0 / 180.0 * M_PI);
  reg.setCurvatureThreshold (1.0);

  std::vector <pcl::PointIndices> clusters;
  reg.extract (clusters);





  // METRICS  ----------------------------------------------------------------------



  std::cout << "Clusters Found =  " << clusters.size () << std::endl;

  int counter = 0;


  for (int i = 0 ; i<clusters.size ();i = i+1)
    {
      std::cout<<"Saving Cluster"<<i<<std::endl;
      counter = 0;
      while (counter < clusters[i].indices.size ())
        {
          std::cout << clusters[i].indices[counter] << ", ";
          counter++;
          if (counter % 10 == 0)  std::cout << std::endl;
        }
      std::cout << std::endl<< std::endl;
    }

  // ISOLATING INDIVIDUAL SEGMENTS 


  

 


  
  // while (counter < clusters[0].indices.size ())
  // {
  //   std::cout << clusters[0].indices[counter] << ", ";
  //   counter++;
  //   if (counter % 10 == 0)
  //     std::cout << std::endl;
  // }
  // std::cout << std::endl;

  pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud ();
  pcl::visualization::CloudViewer viewer ("Cluster viewer");
  viewer.showCloud(colored_cloud);
  while (!viewer.wasStopped ())
  {
  }

  return (0);
}
