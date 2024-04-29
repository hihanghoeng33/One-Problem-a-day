float find_uniq(const std::vector<float> &v)
{
  std::vector<float> unique;

  for(size_t i = 0; i < v.size(); i++){
    bool isUnique = true;
    for(size_t j = 0; j < v.size(); j++){
      if(i != j && v[i] == v[j]){
        isUnique = false;
        break;
      }
    }
    if(isUnique){
      unique.push_back(v[i]);
    }
  }
  
  if (!unique.empty()) {
    return unique[0];
  } else {
    return 0;
  }
}
