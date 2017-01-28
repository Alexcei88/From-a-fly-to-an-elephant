#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <list>

/**
 * @brief Слово
 */
class World
{
public:
    World(const std::string& world, const World* parent = nullptr);

    /**
     * @brief AddMutation - добавление мутации для текущего слова
     * @param world - объект с мутацией
     */
    void AddMutation(const World *world);

    /**
     * @brief IsOneDegreeMutation - опередить, отличается ли передаваемое слово на одну букву от текущего
     * @param world - мутируемое слово
     * @return true - если текущее слово отличается от передаваемого ровно на одну букву
     * иначе false
     */
    bool IsOneDegreeMutation(const std::string& world) const;


    bool operator == (const World& world);

    /**
     * @brief GetParent - получить родителя слова
     * @return
     */
    const World* GetParent() const;

    /**
     * @brief GetWorld - получить слово
     * @return
     */
    const std::string& GetWorld() const;

private:

    /**
     * @brief _world - слово
     */
    const std::string _world;

    /**
     * @brief _lengthWorld - длина слова
     */
    const size_t _lengthWorld;

    /**
     * @brief _parent - указатель на родительский класс(мутанта-родителя)
     */
    const World* _parent;

    /**
     * @brief _mutationWorlds - список слов мутаций от текущего слова(который отличаются только на одну букву)
     */
    std::list<const World*> _mutationWorlds;

};

#endif // WORLD_H
