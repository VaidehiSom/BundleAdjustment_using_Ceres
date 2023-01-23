#pragma once

class BALProblem {

private:

    int num_cameras_; // no of cameras
    int num_points_; 
    int num_observations_; // no of observations. each observation has x,y coordinate
    int num_parameters_; // 6 for cameras, 3 for pnts
    bool use_quaternions_; // do you want to use quaternions or not

    int *point_index_;     
    int *camera_index_; // pointer to cameras   
    double *observations_; // pointer to obs
    double *parameters_; // pnts to params

    void CameraToAngelAxisAndCenter(const double *camera,
                                    double *angle_axis,
                                    double *center) const;

    void AngleAxisAndCenterToCamera(const double *angle_axis,
                                    const double *center,
                                    double *camera) const;

public:
    /// load bal data from text file
    //! why using explicit?
    //! what can convert implicitely to string / bool?
    explicit BALProblem(const std::string &filename, bool use_quaternions = false);  // explicit constructor will not let implicit conversion happen

    ~BALProblem() {
        delete[] point_index_;
        delete[] camera_index_;
        delete[] observations_;
        delete[] parameters_;
    }

    /// save results to ply pointcloud
    void WriteToPLYFile(const std::string &filename) const;

    void Normalize();

    void Perturb(const double rotation_sigma,
                 const double translation_sigma,
                 const double point_sigma);

    //! using 10 or 9? formula?
    int camera_block_size() const { return use_quaternions_ ? 10 : 9; }

    //! why 3? store in some variable?
    int point_block_size() const { return 3; }

    int num_cameras() const { return num_cameras_; }

    int num_points() const { return num_points_; }

    int num_observations() const { return num_observations_; }

    int num_parameters() const { return num_parameters_; }

    const int *point_index() const { return point_index_; }

    const int *camera_index() const { return camera_index_; }

    const double *observations() const { return observations_; }

    const double *parameters() const { return parameters_; }

    const double *cameras() const { return parameters_; }

    const double *points() const { return parameters_ + camera_block_size() * num_cameras_; }

    double *mutable_cameras() { return parameters_; }

    double *mutable_points() { return parameters_ + camera_block_size() * num_cameras_; }
};
