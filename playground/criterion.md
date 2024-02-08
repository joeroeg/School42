### Increasing Verbosity

To see more details about which tests passed, you can run Criterion tests with increased verbosity. Criterion supports several verbosity levels, controlled by the `CRITERION_VERBOSITY` environment variable. You can set this variable before running your tests to get more detailed output:

- **Level 0** (`-v=0`): Only show test summaries and failed tests.
- **Level 1** (`-v=1`): Also list the names of successful tests.
- **Level 2** (`-v=2`): Show all assertions, even if they don't fail.

To see the names of all tests that passed, you can set `CRITERION_VERBOSITY` to `1` or higher. Here's how you can do it:

#### On Unix-like systems (Linux/macOS):

```bash
CRITERION_VERBOSITY=1 make tests
```

Or you can export the variable for the duration of your shell session:

```bash
export CRITERION_VERBOSITY=1
make tests
```

#### Adding to the Makefile

Alternatively, you can modify your Makefile to include this environment variable whenever tests are run:

```makefile
tests:
    rm -f $(TESTS_BIN) # Force removal of the test binary
    CRITERION_VERBOSITY=1 $(MAKE) $(TESTS_BIN) # Rebuild the test binary
```

### Criterion Command Line Arguments

Criterion also supports command-line arguments that can modify its behavior, including verbosity. If you're executing `tests_bin` directly (outside of `make`), you can pass these arguments directly:

```bash
./tests_bin --verbose=1
```

Or in your Makefile:

```makefile
$(TESTS_BIN): $(TESTS_OBJ)
    $(CC) -o $@ $^ $(LIBS) $(CRITERION) $(INCLUDES)
    ./$(TESTS_BIN) --verbose=1
```

This command will run your tests with verbosity level 1, where it lists successful tests.
