# cpp-learning

## 设计模式
### 设计原则
- 单一职责
- 开闭原则
- 里式替换
- 接口隔离
- 依赖倒置
- KISS
- DRY：不要重复
- 高内聚、松耦合
- 迪米特法则: 不要依赖类，依赖接口


设计模式代码参考: [https://github.com/JakubVojvoda/design-patterns-cpp](https://github.com/JakubVojvoda/design-patterns-cpp)

### 类型

#### 创建型
- 工厂模式：
  - [抽象工厂:提供一个创建一系列相关或相互依赖对象的接口，而无须指定它们的具体类。](https://github.com/13sai/cpp-learning/blob/master/%E5%88%9B%E5%BB%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/abstractFactory.cpp)
  - [工厂方法:定义一个用于创建对象的接口，让子类决定实例化哪一个类，Factory Method使一个类的实例化延迟到了子类。](https://github.com/13sai/cpp-learning/blob/master/%E5%88%9B%E5%BB%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/factoryMethod.cpp)
- [单例模式：保证一个类只有一个实例，并提供一个访问它的全局访问点。](https://github.com/13sai/cpp-learning/blob/master/%E5%88%9B%E5%BB%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/singleton.cpp)
- [建造者模式：将一个复杂对象的构建与他的表示相分离，使得同样的构建过程可以创建不同的表示。](https://github.com/13sai/cpp-learning/blob/master/%E5%88%9B%E5%BB%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/builder.cpp)


#### 行为型
- [策略模式：定义一系列的算法，把他们一个个封装起来，并使他们可以互相替换，本模式使得算法可以独立于使用它们的客户。](https://github.com/13sai/cpp-learning/blob/master/%E8%A1%8C%E4%B8%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/strategy.cpp)
- [责任链模式：使多个对象都有机会处理请求，从而避免请求的送发者和接收者之间的耦合关系](https://github.com/13sai/cpp-learning/blob/master/%E8%A1%8C%E4%B8%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/chain.cpp)
- [观察者模式：定义对象间一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知自动更新。](https://github.com/13sai/cpp-learning/blob/master/%E8%A1%8C%E4%B8%BA%E5%9E%8B%E6%A8%A1%E5%BC%8F/observer.cpp)
- 模板模式：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中，Template Method使得子类可以不改变一个算法的结构即可以重定义该算法得某些特定步骤。


#### 结构型
- [装饰器模式：动态地给一个对象增加一些额外的职责，就增加的功能来说，Decorator模式相比生成子类更加灵活。](https://github.com/13sai/cpp-learning/blob/master/%E7%BB%93%E6%9E%84%E5%9E%8B%E6%A8%A1%E5%BC%8F/decorator.cpp)
- [适配器模式：将一类的接口转换成客户希望的另外一个接口，Adapter模式使得原本由于接口不兼容而不能一起工作那些类可以一起工作。](https://github.com/13sai/cpp-learning/blob/master/%E7%BB%93%E6%9E%84%E5%9E%8B%E6%A8%A1%E5%BC%8F/adapter.cpp)
