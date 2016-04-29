#Class music

##private:

·unique_ptr<Impl> m_impl

###Music::Impl()

·Mix_Music * const music → get the music and turn's to const;

####private:

·Mix_Music * const music

#####Music::Music()

·Mix_Music* const music

#####Music::from_file()

·const string& path → music's path
·Music * m
