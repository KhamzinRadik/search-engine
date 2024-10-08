#pragma once

/**
 * @file ConverterJson.h
 * @brief Header file for the ConverterJson class, which provides functionality for converting JSON data.
 */

#include "utils/defs.h"
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"


class ConverterJSON {
public:

    /**
    * Get the Instance object of ConverterJSON class
    * @return instance of the singleton
    */
    static ConverterJSON *getInstance();

    /**
     * Get the files content in string vector form
     * @return content of files listed in config.json
     */
    std::vector<std::string> getTextDocuments();

    /**
     * Get the max responses per request
     * @return max responses count
     */
    int getResponsesLimit() const;

    /**
     * Get the Requests from requests.json
     * @return requests vector
     */
    std::vector<std::string> getRequests();

    /**
     * Put requests results into answers.json file
     * @param[in] answers - vector of answers to be placed into answers.json file
     */
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

    /**
     * Read config file specified in CONFIG_FILE_PATH
     */
    void readConfigFile(std::string path = CONFIGS_DIR);

    /**
     * Read request file specified in REQUEST_FILE_PATH
     */
    void readRequestFile(std::string path = REQUESTS_DIR);

    /**
     * Get maximal responses quantity, which can be returned be Search Server
     * @return maximal responses quantity
     */
    int getMaxResponses() const;

private:
    ConverterJSON() = default; // private constructor for singleton realization
    static ConverterJSON *instance;
    std::string applicationName;
    std::string applicationVersion;
    int maxResponses{5};
    std::vector<std::string> resourcesPaths;
    std::vector<std::string> textDocuments;
    std::vector<std::string> requests;
};



