#!/bin/bash
# test_concurrency.sh - Thread safety test using Valgrind helgrind

set -e

echo "Running thread safety test..."

# Navigate to project root (script is in tests/)
cd "$(dirname "$0")/.."

# Check if telemetry_system exists
if [ ! -f "./telemetry_system" ]; then
    echo "Error: telemetry_system not found. Run 'make' first."
    exit 1
fi

# Test: Multiple concurrent operations don't crash or race
echo -e "start\nstart\nstart\nstatus\nlatest\nstop\nstop\nexit" | \
    timeout 30 valgrind --tool=helgrind --error-exitcode=42 ./telemetry_system 2>&1 | \
    tee valgrind_output.txt

# Check Valgrind exit code
VALGRIND_EXIT=$?
if [ $VALGRIND_EXIT -eq 42 ]; then
    echo "✗ Thread safety test FAILED - Helgrind detected errors"
    cat valgrind_output.txt
    rm -f valgrind_output.txt
    exit 1
fi

# Double-check error summary
if grep -q "ERROR SUMMARY: 0 errors" valgrind_output.txt; then
    echo "✓ Thread safety test PASSED"
    rm -f valgrind_output.txt
    exit 0
else
    echo "✗ Thread safety test FAILED - Check output"
    cat valgrind_output.txt
    rm -f valgrind_output.txt
    exit 1
fi