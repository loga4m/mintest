### Version Sep3.2025
- Separated template function implementations from header files (using another header file)
- Removed support for `vector<string>`
- Added:
  - generic `EXPECT_EQ*` for containers that implement `.at(), .size()` functions
  - support for primitive types (that are supported by to_string)
  - recreated `EXPECT_EQ` for specific template types by changing names
- Run tests written by Claude.ai in `mintest` to test `mintest` 
