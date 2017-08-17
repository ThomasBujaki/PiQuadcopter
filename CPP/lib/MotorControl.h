class MotorControl {
	public:
		MotorControl();
		void setMotorThrust(int motorIndex, int percentage);
		void setThrustOfAllMotors(int percentage);
};
