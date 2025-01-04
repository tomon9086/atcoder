# AtCoder

## Environment

- C++20 (GCC 12)

## Usage

### Initialize Contest

Run this script before every contest.

```console
make init
```

_Contest ID will be saved to .env file._

Output example

```plain
Contest ID? (default: ): abc000
Problem Number? (default: ): a

Initialized!
  Contest ID     : abc000
  Problem Number : a
```

### Create a new answer

```console
make new
```

### Create a new test input

```console
make new_test
```

(with Pasteboard content)

```console
pbpaste | make new_test
```

### Run with all test inputs

```console
make test
```

### (Optional) Temporary Contest ID

```console
c=abc000 q=a make new
```
