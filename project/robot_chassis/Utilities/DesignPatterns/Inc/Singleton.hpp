#ifndef DESIGN_PATTERNS_SINGLETON_H
#define DESIGN_PATTERNS_SINGLETON_H

namespace DesignedPattern
{
/* Safe after c++11 */
template <typename T>
class Singleton
{
  private:
	Singleton() {}
	~Singleton() {}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
  public:
	static T& getInstance() {
		static T instance;
		return instance;
	}
};

} /* namespace DesignedPattern */

#endif // ! DESIGN_PATTERNS_SINGLETON_H
