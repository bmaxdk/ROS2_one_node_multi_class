/// origianl
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <map>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "classB.cpp"

// class Publisherc: public rclcpp::Node
// {
// public:
//   Publisherc()

// private:
//   rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_p;
//   std::string name;

//   // public:
//   //   Publisherc(): Node(rclcpp::NodeOptions options);
//   //   // void setname(std::string s);
//   //   // void pub;


// };

// Publisherc::Publisherc(rclcpp::NodeOptions options) : Node("params_example", options)
// {
//   RCLCPP_INFO(get_logger(), "[ParamsExample]: initializing");
// }

// // Publisherc::setname(std::string ns){
// //   name = ns;
// // }
// // Publisherc::pub(rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publish){
// //   publisher_p = this->create_publisher<std_msgs::msg::String>(name, 10);
// // }
// /////////////////
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
// /////////////
using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      // publisher_ = this->create_publisher<std_msgs::msg::String>("/topic/test", 10);
      pub_map[1] = this->create_publisher<std_msgs::msg::String>("/topic/test", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      // auto message = std_msgs::msg::String();
      std_msgs::msg::String message;
      // message = std::make_unique<std_msgs::msg::String>();
      message.data = "Hello, world! " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      pub_map[1]->publish(message);
      
      std::shared_ptr<ClassB> class_b;
      class_b = std::make_shared<ClassB>(shared_from_this());
      // class_b->publisher_= this->create_publisher<std_msgs::msg::String>("/class_B", 10);
      message.data = "message_origin: object class B";
      // class_b->publisher_->publish(message);
      // auto massage2 = std::make_unique<std_msgs::msg::String>();
      pub_map[2] = class_b->publisher_;
      pub_map[2]->publish(message);
      // pub_map.erase(1);
      pub_map[1] = this->create_publisher<std_msgs::msg::String>("/origin", 10);
      message.data = "message_origin: A";
      pub_map[1]->publish(message);
      // publisher_2 = class_b->publisher_;
      // publisher_2->publish(message);

      // std::shared_ptr<ClassB> class_c;
      // class_c = std::make_shared<ClassB>(shared_from_this(),);
      // message.data = "pub_map3";
      // pub_map[3] = class_b->publisher_;
      // pub_map[3]->publish(message);

    }
    rclcpp::TimerBase::SharedPtr timer_;
    std::map<int, rclcpp::Publisher<std_msgs::msg::String>::SharedPtr> pub_map;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    // rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_2;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}






// #include <chrono>
// #include <functional>
// #include <memory>
// #include <string>
// #include <map>
// #include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"
// #include "classB.cpp"

// // class Publisherc: public rclcpp::Node
// // {
// // public:
// //   Publisherc()

// // private:
// //   rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_p;
// //   std::string name;

// //   // public:
// //   //   Publisherc(): Node(rclcpp::NodeOptions options);
// //   //   // void setname(std::string s);
// //   //   // void pub;


// // };

// // Publisherc::Publisherc(rclcpp::NodeOptions options) : Node("params_example", options)
// // {
// //   RCLCPP_INFO(get_logger(), "[ParamsExample]: initializing");
// // }

// // // Publisherc::setname(std::string ns){
// // //   name = ns;
// // // }
// // // Publisherc::pub(rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publish){
// // //   publisher_p = this->create_publisher<std_msgs::msg::String>(name, 10);
// // // }
// // /////////////////
// // class ClassB {
// //   public:
// //     ClassB(rclcpp::Node::SharedPtr node); // constructor

// //     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
      
// //   private:
// //     rclcpp::Node::SharedPtr node_;
    

// // };
// // ClassB::ClassB(rclcpp::Node::SharedPtr node) : node_(node) {
// //   RCLCPP_INFO(node->get_logger(), "classb:");
// //   publisher_ = node->create_publisher<std_msgs::msg::String>("a", 10);
// //   auto message = std_msgs::msg::String();

// //   message.data = "Ay, world! ";
// //   publisher_->publish(message);
// // }
// // /////////////
// using namespace std::chrono_literals;

// /* This example creates a subclass of Node and uses std::bind() to register a
// * member function as a callback from the timer. */

// class MinimalPublisher : public rclcpp::Node
// {
//   public:
//     MinimalPublisher()
//     : Node("minimal_publisher"), count_(0)
//     {
//       // publisher_ = this->create_publisher<std_msgs::msg::String>("/topic/test", 10);
//       pub_map[1] = this->create_publisher<std_msgs::msg::String>("/topic/test", 10);
//       timer_ = this->create_wall_timer(
//       500ms, std::bind(&MinimalPublisher::timer_callback, this));
//     }

//   private:
//     void timer_callback()
//     {
//       // auto message = std_msgs::msg::String();
//       // std_msgs::msg::String message;
//       auto message = std::make_unique<std_msgs::msg::String>();
//       message->data = "Hello, world! " + std::to_string(count_++);
//       RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message->data.c_str());
//       pub_map[1]->publish(std::move(message));
      
//       std::shared_ptr<ClassB> class_b;
//       class_b = std::make_shared<ClassB>(shared_from_this());
//       // class_b->publisher_= this->create_publisher<std_msgs::msg::String>("/class_B", 10);
//       message->data = "A";
//       // class_b->publisher_->publish(message);
//       // auto massage2 = std::make_unique<std_msgs::msg::String>();
//       pub_map[2] = class_b->publisher_;
//       pub_map[2]->publish(std::move(message));
//       // publisher_2 = class_b->publisher_;
//       // publisher_2->publish(message);
//     }
//     rclcpp::TimerBase::SharedPtr timer_;
//     std::map<int, rclcpp::Publisher<std_msgs::msg::String>::SharedPtr> pub_map;
//     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
//     // rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_2;
//     size_t count_;
// };

// int main(int argc, char * argv[])
// {
//   rclcpp::init(argc, argv);
//   rclcpp::spin(std::make_shared<MinimalPublisher>());
//   rclcpp::shutdown();
//   return 0;
// }

