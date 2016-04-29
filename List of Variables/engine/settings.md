#Class settings

##public:

###Settings::from_file()

·const string& path

###Settings::save()

·const string& path → where the save will be stored
·map< string, map<string, string> > sections() const →
·template<typename T> T

###Settings::read() const

·const string& section
·const string& name
·const T& default_value
·auto it
·auto jt
·istringstream iss

###Settings::write() const

·const string& section
·const string& name
·const T& value

###Settings::write()

·const string& section
·const string& name
·const T& value
·ostringstream os

###Settings::ltrim()

·const string& s
·int pos

###Settings::from_file()

·const string& path
·Settings * settings = new Settings();

###Settings::inifile()

·path
·State state
·char c

###Settings::save()

·const string& path

Settings::outfile()

·path
·auto p
