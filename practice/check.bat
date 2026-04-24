@echo off
:loop
 
		    data.exe>data.in
		    lanqiao1.exe<data.in>data.out	
			baoli.exe<data.in>data.ans	
			fc data.out data.ans
		    if %errorlevel% neq 0 (type data.in& pause&exit /b)
goto :loop
