check-tui-screen-units:
	clang ./src/TerminalUI/Screen.c ./tests/TerminalUI/ScreenUnitTests.c -o ./build/tui-screen-units -lcunit
	./build/tui-screen-units

check-tui-screen-integration:
	clang ./src/TerminalUI/Screen.c ./tests/TerminalUI/ScreenIntegrationTest.c -o ./build/tui-screen-integration 
	./build/tui-screen-integration
	