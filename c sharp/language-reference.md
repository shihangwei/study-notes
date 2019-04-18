> https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual

1. 修饰符
    1. abstract
    2. async
    3. coonst
    4. Event
    5. extern
    6. in(泛型修饰符)
    7. out(泛型修饰符)
    8. override
    9. readonly
    10. sealed
    11. static
    12. unsafe
    13. **virtual** (c#多态的实现)https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/polymorphism<br/>
        关键字用于修饰方法、属性、索引器或事件申明，并使他们何以在派生类中被重写。<br/>
            备注: 调用虚方法时，将为代替的成员检查该对象的运行时类型。将调用大部分派生类中的该替代成员，如果没有派生类代替该成员，则它可能是原始成员。<br/>
            默认情况下，方法是非虚拟的。不能代替非虚方法。<br/>
            **virtual** 修饰符不能与 **static**、 **abstract**、 **private** 或 **override** 修饰符一起使用。<br/>
    1.  volatile
        