#include "WPILib.h"
#include "Gamepad.h"

class DriveRobot : public IterativeRobot {
	
	//PWM channels:
	static const int DRIVE_FRONT_RIGHT = 1;
	static const int DRIVE_REAR_RIGHT = 2;
	static const int DRIVE_FRONT_LEFT = 3;
	static const int DRIVE_REAR_LEFT = 4;
	
	//Joypad axes:
	static const int AXIS_RIGHT_X = 1;
	static const int AXIS_RIGHT_Y = 2;
	static const int AXIS_LEFT_X = 3;
	static const int AXIS_LEFT_Y = 4;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	
public:
	DriveRobot() {
		drive = new RobotDrive(
				new Victor(DRIVE_FRONT_RIGHT),
				new Victor(DRIVE_REAR_RIGHT),
				new Victor(DRIVE_FRONT_LEFT),
				new Victor (DRIVE_REAR_LEFT)
				);
		gamepad = new Gamepad(1);
	}
	
	void RobotInit(){
		
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
		drive->ArcadeDrive(CurveAcceleration(gamepad->GetLeftY()), gamepad->GetRightX());
	}
	
	float CurveAcceleration(float input){
		return input; //TODO: add acceleration curving
	}
	
};

START_ROBOT_CLASS(DriveRobot);
