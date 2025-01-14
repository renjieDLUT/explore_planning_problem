
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <type_traits>
#include <unordered_map>

namespace {
constexpr char kEmptyFillValue[] = "N/A";
}
class CsvWriter {
public:
  explicit CsvWriter(std::vector<std::string> fields,
                     const std::string &save_path, char seperator = ',')
      : fields_(std::move(fields)), save_path_(save_path),
        seperator_(seperator) {}

  //   ~CsvWriter();

  template <typename T, typename... Args>
  void AppendOneRecord(const std::unordered_map<std::string, T> &field_data,
                       const Args &... args) {
    data_.push_back(std::vector<std::string>(fields_.size()));
    auto &last_record = data_.back();

    InsertField(last_record, field_data);
    AppendOneRecord(args...);
  }

private:
  void AppendOneRecord() {}

  template <typename T>
  typename std::enable_if<std::is_arithmetic<T>::value ||
                              std::is_same<std::string, T>::value ||
                              std::is_same<char[], T>::value,
                          void>::type
  InsertField(std::vector<std::string> &record,
             const std::unordered_map<std::string, T> &insert_data) {
    if (record.size() != fields_.size()) {
      std::cout << " record's size should be equal to fields'!";
      return;
    }

    for (int i = 0; i < fields_.size(); ++i) {
      const std::string &field = fields_[i];
      const auto &iter = insert_data.find(field);
      if (iter != insert_data.end()) {
        if constexpr (std::is_arithmetic<T>::value) {
          record[i] = std::to_string(iter->second);
        } else {
          record[i] = iter->second;
        }
      } else {
        record[i] = kEmptyFillValue;
      }
    }
  }

  const boost::filesystem::path save_path_;
  const char seperator_;
  const std::vector<std::string> fields_;
  std::vector<std::vector<std::string>> data_;
};