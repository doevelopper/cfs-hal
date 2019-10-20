

ByteStream::ByteStream()
    : std::stringstream()
{

}

ByteStream::ByteStream(const ByteStream & other)
    : std::stringstream(other.str())
{
    this->seekp(0, std::ios::end);
}


