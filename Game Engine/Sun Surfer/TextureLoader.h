#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <map>
#include <memory>

struct Texture
{
	Texture(unsigned int id, int width, int height) : handle(id), width(width), height(height) {};

	unsigned int handle;
	int width, height;
};

class TextureLoader
{
public:
	static TextureLoader& Instance();

	bool GetTexture(const std::string& imagepath, std::shared_ptr<const Texture>& outTexture);
	std::shared_ptr<const Texture> GetEmptyTexture(const std::string& name, int width, int height);
	std::shared_ptr<const Texture> GetEmptyShadowMapTexture(const std::string& name, int width, int height);

private:
	typedef std::shared_ptr<const Texture>			TextureSharedPtr;
	typedef std::weak_ptr<const Texture>			TextureWeakPtr;
	typedef std::map<std::string, TextureWeakPtr>	TextureMap;

	TextureLoader() {};

	bool GetLoadedTexture(const std::string& imagepath, TextureSharedPtr& outTexture);
	bool LoadTexture(const std::string& imagepath, TextureSharedPtr& outTexture);
	std::shared_ptr<const Texture> BufferTexture(const std::string& imagepath, unsigned int id, int width, int height);

	TextureMap m_textureMap;
};
#endif // !TEXTURELOADER_H_