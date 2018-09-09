/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

/*
	Classes that differ in the arguments of a function.
	Base class allows the function to be called with all the arguments,
	according to the derived class.
*/

class Transformation {

public:
	virtual Mat applyTransformation(Mat frame) { return Mat(); };
	string name;
};

class NoParameters : public Transformation {
private:
	std::function<Mat(Mat)> func;

public:
	NoParameters(std::function<Mat(Mat)> func, string name) {
		NoParameters::func = func;
		NoParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame);
	}
};

class OneIntParameters : public Transformation {
private:
	std::function<Mat(Mat, int)> func;
	int arg1;

public:
	OneIntParameters(std::function<Mat(Mat, int)> func, int arg1, string name) {
		OneIntParameters::func = func;
		OneIntParameters::arg1 = arg1;
		OneIntParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1);
	}
};

class OneFloatParameter : public Transformation {
private:
	std::function<Mat(Mat, float)> func;


public:
	double arg1, arg2;
	OneFloatParameter(std::function<Mat(Mat, float)> func, float arg1, string name) {
		OneFloatParameter::func = func;
		OneFloatParameter::arg1 = arg1;
		OneFloatParameter::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1);
	}
};

class TwoIntParameters : public Transformation {
private:
	std::function<Mat(Mat, int, int)> func;
	int arg1;
	int arg2;

public:
	TwoIntParameters(std::function<Mat(Mat, int, int)> func, int arg1, int arg2, string name) {
		TwoIntParameters::func = func;
		TwoIntParameters::arg1 = arg1;
		TwoIntParameters::arg2 = arg2;
		TwoIntParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2);
	}
};

class IntScalarParameters : public Transformation {
private:
	std::function<Mat(Mat, int, Scalar)> func;
	int arg1;
	Scalar arg2;

public:
	IntScalarParameters(std::function<Mat(Mat, int, Scalar)> func, int arg1, Scalar arg2, string name) {
		IntScalarParameters::func = func;
		IntScalarParameters::arg1 = arg1;
		IntScalarParameters::arg2 = arg2;
		IntScalarParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2);
	}
};


class IntDoubleParameters : public Transformation {
private:
	std::function<Mat(Mat, int, double)> func;
	int arg1;
	double arg2;

public:
	IntDoubleParameters(std::function<Mat(Mat, int, double)> func, int arg1, double arg2, string name) {
		IntDoubleParameters::func = func;
		IntDoubleParameters::arg1 = arg1;
		IntDoubleParameters::arg2 = arg2;
		IntDoubleParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2);
	}
};

class TwoDoubleParameters : public Transformation {
private:
	std::function<Mat(Mat, double, double)> func;
	

public:
	double arg1, arg2;
	TwoDoubleParameters(std::function<Mat(Mat, double, double)> func, double arg1, double arg2, string name) {
		TwoDoubleParameters::func = func;
		TwoDoubleParameters::arg1 = arg1;
		TwoDoubleParameters::arg2 = arg2;
		TwoDoubleParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2);
	}
};

class TwoVec3bParameters : public Transformation {
private:
	std::function<Mat(Mat, Vec3b, Vec3b)> func;
	Vec3b arg1, arg2;

public:
	TwoVec3bParameters(std::function<Mat(Mat, Vec3b, Vec3b)> func, Vec3b arg1, Vec3b arg2, string name) {
		TwoVec3bParameters::func = func;
		TwoVec3bParameters::arg1 = arg1;
		TwoVec3bParameters::arg2 = arg2;
		TwoVec3bParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2);
	}
};

class TwoDoubleIntParameters : public Transformation {
private:
	std::function<Mat(Mat, double, double, int)> func;
	double arg1, arg2;
	int arg3;

public:
	TwoDoubleIntParameters(std::function<Mat(Mat, double, double, int)> func, double arg1, double arg2, int arg3, string name) {
		TwoDoubleIntParameters::func = func;
		TwoDoubleIntParameters::arg1 = arg1;
		TwoDoubleIntParameters::arg2 = arg2;
		TwoDoubleIntParameters::arg3 = arg3;
		TwoDoubleIntParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2, arg3);
	}
};

class ThreeIntParameters : public Transformation {
private:
	std::function<Mat(Mat, int, int, int)> func;
	int arg1, arg2, arg3;

public:
	ThreeIntParameters(std::function<Mat(Mat, int, int, int)> func, int arg1, int arg2, int arg3, string name) {
		ThreeIntParameters::func = func;
		ThreeIntParameters::arg1 = arg1;
		ThreeIntParameters::arg2 = arg2;
		ThreeIntParameters::arg3 = arg3;
		ThreeIntParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2, arg3);
	}
};


class FourIntParameters : public Transformation {
private:
	std::function<Mat(Mat, int, int, int, int)> func;
	int arg1, arg2, arg3, arg4;

public:
	FourIntParameters(std::function<Mat(Mat, int, int, int, int)> func, int arg1, int arg2, int arg3, int arg4, string name) {
		FourIntParameters::func = func;
		FourIntParameters::arg1 = arg1;
		FourIntParameters::arg2 = arg2;
		FourIntParameters::arg3 = arg3;
		FourIntParameters::arg4 = arg4;
		FourIntParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2, arg3, arg4);
	}
};

class ThreeIntDoubleParameters : public Transformation {
private:
	std::function<Mat(Mat, int, int, int, double)> func;
	int arg1, arg2, arg3;
	double arg4;
public:
	ThreeIntDoubleParameters(std::function<Mat(Mat, int, int, int, double)> func, int arg1, int arg2, int arg3, double arg4, string name) {
		ThreeIntDoubleParameters::func = func;
		ThreeIntDoubleParameters::arg1 = arg1;
		ThreeIntDoubleParameters::arg2 = arg2;
		ThreeIntDoubleParameters::arg3 = arg3;
		ThreeIntDoubleParameters::arg4 = arg4;
		ThreeIntDoubleParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2, arg3, arg4);
	}
};

class ShiTomasiCornerDetectionParameters : public Transformation {
private:
	std::function<Mat(Mat, int, double, double, int, bool, double)> func;
	int arg1, arg4;
	double arg2, arg3, arg6;
	bool arg5;
public:
	ShiTomasiCornerDetectionParameters(std::function<Mat(Mat, int, double, double, int, bool, double)> func, int arg1, double arg2, double arg3, int arg4, bool arg5, double arg6, string name) {
		ShiTomasiCornerDetectionParameters::func = func;
		ShiTomasiCornerDetectionParameters::arg1 = arg1;
		ShiTomasiCornerDetectionParameters::arg2 = arg2;
		ShiTomasiCornerDetectionParameters::arg3 = arg3;
		ShiTomasiCornerDetectionParameters::arg4 = arg4;
		ShiTomasiCornerDetectionParameters::arg5 = arg5;
		ShiTomasiCornerDetectionParameters::arg6 = arg6;
		ShiTomasiCornerDetectionParameters::name = name;
	}

	Mat applyTransformation(Mat frame) {
		return func(frame, arg1, arg2, arg3, arg4, arg5, arg6);
	}
};

