
int main():






int main(int argc, char** argv)
{
  ros::init(argc, argv, "vision_node");

  ros::NodeHandle nh;
  message_filters::Subscriber<Image> image1_sub(nh, "image1", 1);
  message_filters::Subscriber<Image> image2_sub(nh, "image2", 1);

  typedef sync_policies::ApproximateTime<Image, Image> MySyncPolicy;
  // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
  Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), image1_sub, image2_sub);
  sync.registerCallback(boost::bind(&callback, _1, _2));

  ros::spin();

  return 0;
}