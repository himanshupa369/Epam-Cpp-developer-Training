| Return Type         | Lifetime Management | Copy Overhead       | Can Modify Original? | Use When...                      |
| ------------------- | ------------------- | ------------------- | -------------------- | -------------------------------- |
| `ObjectType`        | New object          | Yes (but optimized) | No                   | Creating new objects             |
| `ObjectType&`       | Same as original    | No                  | Yes                  | Referring to existing members    |
| `const ObjectType&` | Same as original    | No                  | No                   | Access existing object read-only |
