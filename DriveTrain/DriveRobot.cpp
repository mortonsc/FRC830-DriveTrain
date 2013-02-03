#include "WPILib.h"
#include "Gamepad.h"
//#include <DriverStationLCD.h>

class DriveRobot : public IterativeRobot {
	
	//PWM channels:
	static const int DRIVE_RIGHT = 1;
	static const int DRIVE_LEFT = 2;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	DriverStationLCD * lcd;
public:
	DriveRobot() {

	}
	
	void RobotInit(){
		drive = new RobotDrive(
				new Victor(DRIVE_RIGHT),
				new Victor(DRIVE_LEFT)
				);
		
		gamepad = new Gamepad(1);
		lcd = DriverStationLCD::GetInstance();
		
	}
	
	void DisabledInit(){
		drive->ArcadeDrive(0.0f, 0.0f);
	}
	
	void AutonInit(){
		
	}
	
	void TeleopInit(){
		
	}
	
	void DisabledPeriodic(){
		drive->ArcadeDrive(0.0f, 0.0f);
	}
	
	void AutonPeriodic(){
		
	}
	
	void TeleopPeriodic(){
		float forwardSpeed = -gamepad->GetLeftY();
		float sideSpeed = gamepad->GetRightX();
		drive->ArcadeDrive(CurveAcceleration(forwardSpeed), sideSpeed);
		lcd->PrintfLine(DriverStationLCD::kUser_Line1,"LEFT Y %f",forwardSpeed);
		lcd->PrintfLine(DriverStationLCD::kUser_Line2,"RIGHT X %f",sideSpeed);
	
		lcd->UpdateLCD();	
	}
	
	float CurveAcceleration(float input) {
		return input;
	}
};

START_ROBOT_CLASS(DriveRobot);
