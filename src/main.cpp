#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std::chrono_literals;

int main() {
  // 创建渲染窗口
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Hello SFML!");

  while (window.isOpen()) {
    // 事件处理
    while (const std::optional event = window.pollEvent()) {
      // 窗口关闭
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      // 改变窗口大小
      else if (const auto* e = event->getIf<sf::Event::Resized>()) {
        printf("%d, %d\n", window.getSize().x, window.getSize().y);
        printf("%d, %d\n", e->size.x, e->size.y);
      }
      // 按键按下
      else if (const auto* e = event->getIf<sf::Event::KeyPressed>()) {
        printf("Scan: %d, Code: %d\n", e->scancode, e->code);
      }
      // 文本输入
      else if (const auto* e = event->getIf<sf::Event::TextEntered>()) {
        sf::String s(e->unicode);
        std::cout << "TextEntered: " << s.toAnsiString() << std::endl;
      }
    }

    // 清理窗口内容(可以在这里填充颜色)
    window.clear(sf::Color::Green);

    // 渲染窗口内容
    sf::RectangleShape player(sf::Vector2f({100.23f, 200.46f}));
    player.setPosition({200, 100});
    player.setFillColor(sf::Color::Cyan);
    window.draw(player);
    // std::this_thread::sleep_for(3s);

    // 显示窗口内容
    window.display();
  }
}