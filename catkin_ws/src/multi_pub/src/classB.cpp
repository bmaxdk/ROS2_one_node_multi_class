class ClassB {
  public:
    ClassB(rclcpp::Node::SharedPtr node); // constructor

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
      
  private:
    rclcpp::Node::SharedPtr node_;
    

};
ClassB::ClassB(rclcpp::Node::SharedPtr node) : node_(node) {
  RCLCPP_INFO(node->get_logger(), "Inside classb:");
  publisher_ = node->create_publisher<std_msgs::msg::String>("/classB/Publisher", 10);
  
//   auto message = std_msgs::msg::String();
  auto message = std::make_unique<std_msgs::msg::String>();


  message->data = "message from classB";
  publisher_->publish(std::move(*message));
}

// class ClassB {
//   public:
//     ClassB(rclcpp::Node::SharedPtr node); // constructor

//     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
      
//   private:
//     rclcpp::Node::SharedPtr node_;
    

// };
// ClassB::ClassB(rclcpp::Node::SharedPtr node) : node_(node) {
//   RCLCPP_INFO(node->get_logger(), "classb:");
//   publisher_ = node->create_publisher<std_msgs::msg::String>("a", 10);
//   auto message = std_msgs::msg::String();

//   message.data = "Ay, world! ";
//   publisher_->publish(message);
// }