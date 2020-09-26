# Work Documentation and Code Repository 

__Samarth Negi__ <br>
Created : 25 September 2020 



Most projects have their own README.md's with basic installation. 



|Folder|Project  |Description  | Tech |
|---|---|---|---|
|djiparsetxt|WTG  |Decryption of DJI log files<br> _check readme for instructions_  |C++|
|better-livox-camera-calibration|WTG, Depth Calculation  |Camera Calibration Tool Built as a Replacement for the one provided by Livox |Python, OpenCV |
|livox-horizon|WTG|Interface instructions:  __HARDWARE__ for the livox horizon|Hardware|
|point-cascade-matching|WTG|Voxelisation implemented in python and pandas __[old code, pre Tiruppur]__|Python, Pandas|
|perspective|WTG, Projection|Projection of 3D into 2D, implemented in python and matplotlib. <br>_Uday Sir has a better method in threeJS, use that instead of this_ |Python, Matplotlib|
|ROS-realtime-voxelisation|WTG|Realtime Voxelisation of Lidar Data, Using ROS : __Use my ws_livox environment on linux__ |ROS, C++, PCL | 
|kml-generator|WTG|KML File Generator for DJI Flight Paths __[POC1: Single Blade]__ |XML, Python|
|pcl-mls|WTG, Point Cloud General|Cleaning of Pointclouds using PCL,  Good Generic Method and Parameters, Straight up add to your pipeline for sharper pointclouds | C++, PCL| 
|WTG-testing|WTG|Experiment notebooks created before Uday Sir wrote his WTG code.<br> LOTS of generic functions and good modules here. Please read through if needed help in the WTG final stage | Python, GIS |
|wtg-old|WTG|Old WTG code written while in Delhi. <br>Contains good pcl modules and some experiments.<br>None of it is part of the final WTG. Use for pointcloud reference. | Python, C++, PCL|
|livox-csvCapture|WTG|_Production Code_ : For any linux device connected to a livox lidar, this code generates csv files for whatever current scene is being captured| Python, C++, PCL|



________________________________________________________________
<br>
<br>
<br>

# GENERAL INSTRUCTIONS AND GUIDES 
## PCL 
- Easiest way of getting pcl up and running on a system is to install ROS `desktop-full-install` version. 
- The only problem that arises in PCL is that sometimes ROS or Eigen installation clashes classnames in the scope.<br> If you want to use such functions, install PCL independently. 

## ROS 
- Run the `desktop-full-install` installation as given on the ROS Website. 
- If any package doesn't compile : Look at the error, it might just be a dependency issue [80% of the cases for me].
- Clone and use my ws_livox workspace, keep original for reference as it is heavily modified and has lots of 
optimisations that you can use in the future. 
- Install new packages in src, activate workspace in devel.
- ROS DOCUMENTATION is BEAUTIFULLY WRITTEN : Read it to get a better understanding of ROS. Head to Toe. [link](http://wiki.ros.org/ROS/Tutorials).

    ### Setting Up a ROS Workspace with Livox Configuration
    1. Run the `desktop-full-install` installation if you haven't.
    2. Create a new workspace folder : `mkdir folderName`.
    3. Make a folder inside the workspace called `src`.
    4. run `catkin_make` to initialize the workspace.  
    5. clone and install [this](https://github.com/Livox-SDK/livox_ros_driver) repository in your home folder.  [instruction on how to install in linux](https://github.com/Livox-SDK/Livox-SDK/blob/master/README.md)
    6. Install livox driver to ROS Environment : clone [this](https://github.com/Livox-SDK/livox_ros_driver) repo into the workspace src folder
    7. If any errors occur, they are due to dependencies. 2 ways to fix dependency issues. 
        - __ROS PACKAGE__ :Search `packageName ROS` on google and get ros package and place them in src and then `catkin_make` 
        - __LINUX MODULE__ : find modules and install them using `sudo apt-get install`. <br>_NOTE : some dependencies are ROS Version Based._
    
    ### Working with my ROS environment [WTG/ Livox Development Environment : ws_livox]
    1. 


## LIVOX HORIZON 
- 12-20 V Required to power the lidar  
- For Connections in Ubuntu 
    - __READ MANUAL__ : Set static IP as specified in the Ubuntu network manual. 
    - Set static IP again using the `ifconfig` command. 
- Using the livox viewer. 
    - Browse to the location of the livox viewer and locate the `.sh` bash script 
    - RUN `./<fileName>.sh`

## Resources 
- Resource Folder Contains screenshots and stuff I collected during research, will be useful later. 
- Resource Folder Contains environment yml's. 
- Notion: [WTG PIPLEINE AND INITIAL IDEAS](https://www.notion.so/WTG-e81f79e66fb44dbd89975f065bd07eb9)
- Notion : [ROS - Good Features To Remeber, by me](https://www.notion.so/smngi20/Robot-Operating-System-0b39f68582b244deb6a75b03be674457)
<br>
<br>
<br>





## PLEASE NOTE 
A copy of the following Repository is also saved on my official account drive : samarth.negi@phicode.io<br>
My Older Projects : Seggro, Insight, CATPRO are all present on my official account drive. 

Thanks and Bye 