// USE SHIFT CLICK 



#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

void clickAndView (const pcl::visualization::PointPickingEvent& event, void* viewer_void)
{
  std::cout << "[INOF] Point picking event occurred." << std::endl;

  float x, y, z;
  if (event.getPointIndex () == -1)
  {
     return;
  }
  event.getPoint(x, y, z);
  std::cout << "[INOF] Point coordinate ( " << x << ", " << y << ", " << z << ")" << std::endl;
}

int main (int argc, char** argv)
{
    pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    pcl::PointCloud<pcl::PointXYZ>::Ptr body (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::io::loadPCDFile ("test.pcd", *body);

    viewer.addPointCloud (body,"body");
    viewer.registerPointPickingCallback (clickAndView, (void*)&viewer);
    viewer.spin();
    
    return 0;
}
