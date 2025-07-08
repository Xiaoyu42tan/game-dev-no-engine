# WHEN TO #include A HEADER FILE IN A HEADER FILE (source: GPT)

| Situation                                                        | Why?                                              |
| ---------------------------------------------------------------- | ------------------------------------------------- |
| You're **inheriting** from a class                               | Compiler needs full base class definition         |
| You're **using the class by value** (e.g., `World world;`)       | Needs to know size/layout                         |
| It's a **member variable** by value (not pointer/ref)            | Same reason — memory layout                       |
| You're **defining an inline function** that uses it              | Function body needs full type                     |
| You're using it in a **template**, e.g., `std::vector<SomeType>` | Templates are compiled at inclusion site          |
| You're **calling methods** or accessing fields                   | Compiler needs to know their existence and layout |

Xiaoyu: if you don't need to #include something in a .h header file as per above, then forward declare it instead. #include whatever u forward declared in the .cpp source file. Else, if a class doesn't appear in the header file, dont include that class.

This should reduce compile times and help solve circular dependency issues.

i hate c++
